#include "codeGenerate.h"

void CodeGenerate::genAsm()
{
    // Generate header
    genAsmHead("main.c");

    // Translate IR
    auto & all_ir = intermediate_stage.getAllCode();
    auto & all_label = intermediate_stage.getAllLabel();
    auto label_begin = all_label.begin();
    auto label_end = all_label.end();
    size_t func_begin;
    for (size_t i = 0; i < all_ir.size(); i ++) {
        // Check label before this ir
        if (all_label.find(i) != label_end) {
            appendAsm(all_label[i].name + ":", false);
        }
        auto & current_ir = all_ir[i];
        switch (current_ir.op)
        {
        case LD:
            genLoadToTmp(current_ir);
            break;
        case ST:
            genStoreFromTmp(current_ir);
            break;
        case ADD:
        case SUB:
            //auto info = intermediate_stage.getTempInfo(current_ir.result.symbol);
            if (current_ir.arg1.is_const && current_ir.val_type == int_type) {
                genIntArithmImmTmp(current_ir);
            } else if (current_ir.arg2.is_const && current_ir.val_type == int_type) {
                genIntArithmTmpImm(current_ir);
            } else {
                genIntArithmTmpTmp(current_ir);
            }
            break;
        case MUL:
        case DIV:
        case MOD:
            genIntArithmTmpTmp(current_ir);
            break;
        case CALL:
            genFuncCall(current_ir);
            break;
        case RETURN:
            moveRetVal(current_ir);
            break;
        case PARAM:
            genFuncParam(current_ir);
            break;
        case FUNC_BEGIN:
            genFuncHead(current_ir);
            func_begin = getAsmNum();
            break;
        case FUNC_END:
            genFuncEnd(current_ir, func_begin);
            break;
        case D_ALLOC:
            genStackInit(current_ir);
            break;
        case G_ALLOC:
            genGlobVar(current_ir);
            break;
        case BEQ:
        case BNE:
        case BLT:
        case BGT:
        case BLE:
        case BGE:
            genBranch(current_ir);
            break;
        case J:
            genJump(current_ir);
            break;
        default:
            break;
        }
    }

    // Generate float section
    genFloatSection();
}

void CodeGenerate::outputToFile(std::string file_name)
{
    file_name = file_name.substr(0, file_name.length() - 4) + "s";
    formatAsm();
    std::ofstream file;
    file.open(file_name);
    for (size_t i = 0; i < format_asm.size(); i ++) {
        file << format_asm[i] << std::endl;
    }
    file.close();
}

void CodeGenerate::formatAsm() {
    for (size_t i = 0; i < asm_array.size(); i ++) {
        asm_line_t & current_line = asm_array[i];
        std::string pos1 = (current_line.pos1 != "") ? inst_padding + current_line.pos1 : "";
        std::string pos2 = (current_line.pos2 != "") ? ", " + current_line.pos2 : "";
        std::string pos3 = (current_line.pos3 != "") ? ", " + current_line.pos3 : "";
        format_asm.push_back(
            current_line.indent +
            current_line.op_info +
            pos1 +
            pos2 +
            pos3
        );
    }
}

// Notice: this may cause problem for nested scope!
// Similar to COPY statement
void CodeGenerate::genLoadToTmp(intmed_code_t &intmed_inst)
{
    std::string temp_name = intmed_inst.result.symbol;
    std::string base = intmed_inst.arg1.symbol;
    copyDscr(intmed_inst.result.symbol, intmed_inst.arg1.symbol);
}

// Copy descriptors from src var to dest var
void CodeGenerate::copyDscr(std::string dest, std::string src)
{
    // Copy AD
    auto old_ad = findAddrDscr(src);
    auto origin = old_ad -> getOriginPos();
    AddrDscr * new_ad = new AddrDscr(dest, origin, old_ad -> getDType());

    auto & old_pos = old_ad -> getAllPos();
    for (size_t i = 0; i < old_pos.size(); i ++) {
        new_ad -> addPos(old_pos[i]);
    }
    addr_dscr.push_back(new_ad);

    // Add to RD
    auto old_reg = old_ad -> getAllRegPos();
    for (size_t i = 0; i < old_reg.size(); i ++) {
        auto old_rd = getRegDscr(old_reg[i]);
        old_rd -> appendVar(dest);
    }
}

// Similar to COPY statement
void CodeGenerate::genStoreFromTmp(intmed_code_t &intmed_inst)
{
    std::string reg_name = getVarInReg(intmed_inst.result, intmed_inst.val_type);

    // gen store
    auto ad = findAddrDscr(intmed_inst.arg1.symbol);
    genStoreFromReg(reg_name, ad);
}

void CodeGenerate::genGlobVar(intmed_code_t &intmed_inst)
{
    std::string name = intmed_inst.arg1.symbol;
    std::string temp = intmed_inst.result.symbol;
    auto info = intermediate_stage.getTempInfo(temp);
    std::string header = ".globl" + inst_padding + name;
    std::string section = ".section" + inst_padding + ((info -> is_const) ? ".srodata" : ".sdata");
    std::string align = ".align" + inst_padding + asm_align_lut[intmed_inst.val_type];
    std::string type = ".type" + inst_padding + name + ", @object";
    size_t item_size = post_grammar_stage.type_to_size[intmed_inst.val_type];
    size_t total_item = info -> num_items;
    size_t total_size = item_size * total_item;
    std::string size = ".size" + inst_padding + name + ", " + std::to_string(total_size);
    std::string label = name + ":";

    appendAsm(header, true);
    appendAsm(section, true);
    appendAsm(align, true);
    appendAsm(type, true);
    appendAsm(size, true);
    appendAsm(label, false);

    auto init_value = splitValList(intmed_inst.arg2.symbol);
    std::string word = asm_word_lut[intmed_inst.val_type];
    size_t i = 0;
    for (; i < init_value.size(); i ++) {
        auto dec = trans_dec_lut[intmed_inst.val_type](init_value[i]);
        appendAsm(word + inst_padding + dec, true);
    }
    if (total_item - init_value.size() > 0) {
        appendAsm(".zero" + inst_padding + std::to_string((total_item - init_value.size()) * item_size), true);
    }

    //
}

void CodeGenerate::genAsmHead(std::string file_name)
{
    std::string file = ".file" + inst_padding + "\"" + file_name + "\"";
    std::string option = ".option" + inst_padding + "nopic";
    std::string arch = ".attribute" + inst_spacing + "arch, " + target_arch;
    std::string ua_acc = ".attribute" + inst_spacing + "unaligned_access, 0";
    std::string stack_align = ".attribute" + inst_spacing + "stack_align, " + std::to_string(stack_align_byte);
    std::string text = ".text";

    appendAsm(file);
    appendAsm(option);
    appendAsm(arch);
    appendAsm(ua_acc);
    appendAsm(stack_align);
    appendAsm(text);
}

void CodeGenerate::genFuncHead(intmed_code_t &intmed_inst)
{
    std::string func_name = intmed_inst.result.symbol;
    std::string text = inst_padding + ".text";
    std::string align = inst_padding + ".align" + inst_padding + "1";
    std::string globl = inst_padding + ".globl" + inst_padding + func_name;
    std::string type = inst_padding + ".type" + inst_padding + func_name + ", @function";
    std::string label = func_name + ":";

    appendAsm(text, false);
    appendAsm(align, false);
    appendAsm(globl, false);
    appendAsm(type, false);
    appendAsm(label, false);

    // Clear
    clearStack(16);

    setDscrForFunc(intmed_inst.result.symbol);
}

void CodeGenerate::setDscrForFunc(std::string func_name)
{
    // Clear non-global AD
    clearLocalAD();

    // Clear all RD
    clearAllRD();

    // Set AD for fparam
    auto fparam = symbol_table.func_symbol_table[func_name].fparam_list;
    size_t i = 0;
    auto iter = fparam.begin();
    for (; iter != fparam.end(); iter ++, i ++) {
        auto item = iter -> second;
        auto reg_name = "a" + std::to_string(i);
        allocAD(item.fparam_name, (var_pos_t) {REGISTER, reg_name}, item.fparam_type);
    }

    // Alloc new reg
    allocRD();

    // Set RD for fparam
    i = 0;
    iter = fparam.begin();
    for (; iter != fparam.end(); iter ++, i ++) {
        auto item = iter -> second;
        auto reg_name = "a" + std::to_string(i);
        auto rd = getRegDscr(reg_name);
        rd -> appendVar(item.fparam_name);
    }
}

// Register allocation
void CodeGenerate::allocRD()
{
    auto & reg_list = getAllRegDscr();
    // Fix
    for (size_t i = 0; i < caller_saved_fix.size(); i ++) {
        auto rd = new RegDscr(caller_saved_fix[i], REG_FIX);
        reg_list.push_back(rd);
    }
    // Float
    for (size_t i = 0; i < caller_saved_float.size(); i ++) {
        auto rd = new RegDscr(caller_saved_float[i], REG_FLOAT);
        reg_list.push_back(rd);
    }
}

void CodeGenerate::genFuncParam(intmed_code_t &intmed_inst)
{
    std::string reg_name = prefix_lut[intmed_inst.val_type] + "a" + intmed_inst.arg1.symbol;
    std::string var_name = intmed_inst.result.symbol;
    auto reg = getRegDscr(reg_name);
    // Not in this reg
    if (!(reg -> findVar(var_name))) {
        // No x to cover, move out directly
        moveVarOut(reg, "", false);
        // Move to this reg
        getVarOrConstInReg(intmed_inst.result, reg, intmed_inst.val_type);
        // Update RD
        updateDestRD(var_name, reg_name);
        // Update AD
        findAddrDscr(var_name) -> addPos(reg_name);
    }
}

// Notice: gen CALL will not jump to that func
void CodeGenerate::genFuncCall(intmed_code_t &intmed_inst)
{
    clearDscrForCall();
    appendAsm(inst_lut[RV_CALL], intmed_inst.arg1.symbol);

    // Add retval to RD
    std::string ret_reg = prefix_lut[intmed_inst.val_type] + "a0";
    std::string temp_name = intmed_inst.result.symbol;
    auto rd = getRegDscr(ret_reg);
    rd -> appendVar(temp_name);
    // Alloc AD
    var_pos_t pos = (var_pos_t) {REGISTER, ret_reg};
    auto ad = allocAD(temp_name, pos, intmed_inst.val_type);
    ad -> addPos(pos);
}

void CodeGenerate::clearDscrForCall()
{
    for (size_t i = 0; i < caller_saved_fix.size(); i ++) {
        auto rd = getRegDscr(caller_saved_fix[i]);
        // No x to cover, move out directly
        moveVarOut(rd, "", false);
        removeRegFromAll(caller_saved_fix[i]);
    }
    for (size_t i = 0; i < caller_saved_float.size(); i ++) {
        auto rd = getRegDscr(caller_saved_float[i]);
        moveVarOut(rd, "", false);
        removeRegFromAll(caller_saved_float[i]);
    }
}

void CodeGenerate::removeRegFromAll(std::string reg)
{
    for (size_t i = 0; i < addr_dscr.size(); i ++) {
        auto & ad = addr_dscr[i];
        ad -> removePos(reg);
    }
}

// Save with alloc
// Origin must be on stack
void CodeGenerate::saveToStack(reg_name_t reg, std::string var, val_type_t dtype)
{
    auto descriptor = findAddrDscr(var);
    if (descriptor == NULL) {
        // New temp var
        size_t size = post_grammar_stage.type_to_size[dtype];
        descriptor = stackAlloc(var, size, dtype);
    }
    genStoreFromReg(reg, descriptor);
}

// D_ALLOC
void CodeGenerate::genStackInit(intmed_code_t &intmed_inst)
{
    // Alloc
    size_t total_size = intmed_inst.arg1.num_item * post_grammar_stage.type_to_size[intmed_inst.val_type];
    auto new_dscr = stackAlloc(intmed_inst.arg1.symbol, total_size, intmed_inst.val_type);

    // If init
    if (intmed_inst.arg2.symbol != "") {
        // Assign
        auto reg = getReg(intmed_inst.val_type, intmed_inst.arg1.symbol);
        getConstInReg(intmed_inst.arg2.symbol, reg, intmed_inst.val_type);
        updateDestRD(intmed_inst.arg1.symbol, reg -> getRegName());
        updateDestAD(intmed_inst.arg1.symbol, reg -> getRegName());

        // Store
        genStoreFromReg(reg -> getRegName(), intmed_inst.arg1.symbol);
    }
}

void CodeGenerate::moveRetVal(intmed_code_t &intmed_inst)
{
    // Move retval to a0
    auto a0 = getRegDscr("a0");
    if (intmed_inst.arg1.is_const) {
        getConstInReg(intmed_inst.arg1.symbol, a0, intmed_inst.val_type);
    } else {
        getVarInReg(intmed_inst.arg1, a0, intmed_inst.val_type);
    }
}

void CodeGenerate::genFuncEnd(intmed_code_t &intmed_inst, size_t begin_inst)
{
    // Backpatch
    size_t end_inst = getAsmNum();
    backPatchSP(begin_inst, end_inst);

    // Store `ra` and `s0` after header
    size_t stack_size = GET_ALIGNED_BYTE(getStackOff(), stack_align_byte);
    std::string ra_pos = std::to_string(stack_size - 8) + "(sp)";
    std::string s0_pos = std::to_string(stack_size - 16) + "(sp)";
    std::string stack_size_s = std::to_string(stack_size);
    insertAsm(inst_lut[RV_ADDI], "s0", "sp", stack_size_s, begin_inst);
    insertAsm(inst_lut[RV_S] + "d", "s0", s0_pos, begin_inst);
    insertAsm(inst_lut[RV_S] + "d", "ra", ra_pos, begin_inst);
    insertAsm(inst_lut[RV_ADDI], "sp", "sp", "-" + stack_size_s, begin_inst);

    // Load `ra` and `s0`
    appendAsm(inst_lut[RV_L] + "d", "ra", ra_pos);
    appendAsm(inst_lut[RV_L] + "d", "s0", s0_pos);
    appendAsm(inst_lut[RV_ADDI], "sp", "sp", stack_size_s);

    // Return
    appendAsm(inst_lut[RV_JR], std::string("ra"));

    // Tail
    std::string func_name = intmed_inst.result.symbol;
    appendAsm(".size" + inst_padding + func_name + ", .-" + func_name, true);
}

void CodeGenerate::genStoreFromReg(reg_name_t reg, AddrDscr * descriptor)
{
    auto origin = descriptor -> getOriginPos();
    descriptor -> addPos(origin);
    descriptor -> addPos(reg);
    auto dtype = descriptor -> getDType();

    appendAsm(prefix_lut[dtype] + inst_lut[RV_S] + ls_suf_lut[dtype], reg, origin.offset);
}

void CodeGenerate::genStoreFromReg(reg_name_t reg, std::string x)
{
    auto descriptor = findAddrDscr(x);
    genStoreFromReg(reg, descriptor);
}

// Register assignment
RegDscr * CodeGenerate::candidReg(val_type_t dtype)
{
    // We simply kick min out
    auto & all_reg = getAllRegDscr();
    size_t min = INT_MAX;
    size_t min_reg = 0;
    for (size_t i = 0; i < all_reg.size(); i ++) {
        size_t num_var = (all_reg[i] -> getVarList()).size();
        if (num_var < min && reg_type_lut[dtype] == (all_reg[i] -> getRegType())) {
            min_reg = i;
            min = num_var;
        }
    }

    return all_reg[min_reg];
}

void CodeGenerate::moveVarOut(RegDscr * reg, std::string x, bool cover_x)
{
    size_t num_rest;
    auto & all_var = reg -> getVarList();
    std::string reg_name = reg -> getRegName();
    while ((num_rest = all_var.size()) > 0) {
        // Check the first var
        auto v = all_var.begin();
        auto descriptor = findAddrDscr(*v);
        if ((descriptor -> getAllPos()).size() > 0 || cover_x && *v == x) {
            // Somewhere else
            // Or v is x and x is not z
            // Or?
        } else {
            val_type_t dtype = descriptor -> getDType();
            saveToStack(reg_name, *v, dtype);
        }
        all_var.erase(v);
    }
}

RegDscr * CodeGenerate::getRegForSrc(val_type_t dtype, std::string src, std::string x, bool cover_x)
{
    std::string reg;
    RegDscr * ret;
    if ((reg = checkRegForVar(src)) != "") {
        // Already in a reg
        ret = getRegDscr(reg);
    } else {
        // Not in a reg, alloc a new one
        ret = getEmptyRD(dtype);
        if (ret == NULL) {
            // Empty reg not found
            ret = candidReg(dtype);
            moveVarOut(ret, x, cover_x);
        }
        // With no AD, alloc a new one (used for the first time)
        if (findAddrDscr(src) == NULL) {
            allocAD(src, (var_pos_t){REGISTER, ret -> getRegName()}, dtype);
        }
    }

    return ret;
}

RegDscr * CodeGenerate::getRegForDest(val_type_t dtype, std::string dest)
{
    // We just simply use get for src
    return getRegForSrc(dtype, dest, dest, true);
}

// The returning order is y, z, x
std::vector <RegDscr *> CodeGenerate::getReg(val_type_t dtype, intmed_arg_t dest, intmed_arg_t src1, intmed_arg_t src2)
{
    std::vector <RegDscr *> ret;
    // Check y
    bool cover_x = (dest.symbol != src2.symbol);
    auto reg_y = getRegForSrc(dtype, src1.symbol, dest.symbol, cover_x);
    // Check z
    cover_x = (dest.symbol != src1.symbol);
    auto reg_z = getRegForSrc(dtype, src2.symbol, dest.symbol, cover_x);
    // Check x
    auto reg_x = getRegForDest(dtype, dest.symbol);

    ret.push_back(reg_y);
    ret.push_back(reg_z);
    ret.push_back(reg_x);

    return ret;
}

// The returning order is y, x
std::vector <RegDscr *> CodeGenerate::getReg(val_type_t dtype, intmed_arg_t dest, intmed_arg_t src)
{
    std::vector <RegDscr *> ret;
    // Check y
    ret.push_back(getRegForSrc(dtype, src.symbol, dest.symbol, true));
    // Check x
    ret.push_back(getRegForDest(dtype, dest.symbol));

    return ret;
}

RegDscr * CodeGenerate::getReg(val_type_t dtype, std::string dest)
{
    return getRegForDest(dtype, dest);
}

void CodeGenerate::genLoadToReg(intmed_arg_t var, RegDscr * reg, val_type_t dtype)
{
    // From global or stack
    auto ad = findAddrDscr(var.symbol);
    if ((ad -> getOriginPos()).prefix == STACK) {
        genLoadFromStack(ad, reg, dtype);
    } else {
        genLoadFromGlob(ad, reg, dtype);
    }

    // Change rd
    reg -> clearSet(var.symbol);
    // Change ad
    ad -> addPos(reg -> getRegName());
}

void CodeGenerate::genLoadFromStack(AddrDscr * var, RegDscr * reg, val_type_t dtype)
{
    appendAsm(prefix_lut[dtype] + inst_lut[RV_L] + ls_suf_lut[dtype], reg -> getRegName(), (var -> getOriginPos()).offset);
}

void CodeGenerate::genLoadFromGlob(AddrDscr * var, RegDscr * reg, val_type_t dtype)
{
    appendAsm(prefix_lut[dtype] + inst_lut[RV_L] + ls_suf_lut[dtype], reg -> getRegName(), (var -> getOriginPos()).offset);
}

// Notice: use this carefully before update RD!
void CodeGenerate::genMoveToReg(std::string dest, std::string src, val_type_t dtype)
{
    appendAsm(prefix_lut[dtype] + inst_lut[RV_MV] + mv_suf_lut[dtype], dest, src);
}

// Not a const
// with reg specified
void CodeGenerate::getVarInReg(intmed_arg_t var, RegDscr * reg, val_type_t dtype)
{
    if (!(reg -> findVar(var.symbol))) {
        auto all_reg = getRegOfVar(var.symbol);
        if (all_reg.size() > 0) {
            // Existing in another reg
            genMoveToReg(reg -> getRegName(), all_reg[0], dtype);
        } else {
            // Issue a load inst
            genLoadToReg(var, reg, dtype);
        }
    }
}

// With allocation
std::string CodeGenerate::getVarInReg(intmed_arg_t var, val_type_t dtype)
{
    std::string var_name = var.symbol;
    std::string reg_name = checkRegForVar(var_name);
    if (reg_name == "") {
        // t1 is not in a reg, gen load
        auto rd = getReg(dtype, var_name);
        genLoadToReg(var, rd, dtype);
        reg_name = rd -> getRegName();
    }
    return reg_name;
}

// With allocation
std::string CodeGenerate::getConstInReg(intmed_arg_t imm, val_type_t dtype)
{
    std::string const_name = imm.symbol;
    auto rd = getReg(dtype, const_name);
    getConstInReg(const_name, rd, dtype);
    return rd -> getRegName();
}

void CodeGenerate::getConstInReg(std::string imm, RegDscr * reg, val_type_t dtype)
{
    std::string dec_const = trans_dec_lut[dtype](imm);
    if (dtype == int_type || dtype == bool_type) {
        appendAsm(inst_lut[RV_LI], reg, dec_const);
    } else {
        loadFloatImm(reg -> getRegName(), dec_const, dtype);
    }

    // Update RD
    //reg -> clearSet(imm);

    // Update AD
    //auto ad = findAddrDscr(imm);
    //ad -> addPos(reg -> getRegName());
}

void CodeGenerate::loadFloatImm(std::string reg, std::string dec_val, val_type_t dtype)
{
    std::string label = findFloatVal(dec_val, dtype);
    if (label == "") {
        label = getNewFloat(dec_val, dtype);
    }
    appendAsm(prefix_lut[dtype] + inst_lut[RV_L] + ls_suf_lut[dtype], reg, label, base_reg);
}

void CodeGenerate::getVarOrConstInReg(intmed_arg_t var, RegDscr * reg, val_type_t dtype)
{
    if (var.is_const) {
        getConstInReg(var.symbol, reg, dtype);
    } else {
        getVarInReg(var, reg, dtype);
    }
}

std::string CodeGenerate::getVarOrConstInReg(intmed_arg_t var, val_type_t dtype)
{
    std::string ret;
    if (var.is_const) {
        ret = getConstInReg(var, dtype);
    } else {
        ret = getVarInReg(var, dtype);
    }
    return ret;
}

void CodeGenerate::updateDest(std::string x, std::string rx)
{
    // Change Rx
    updateDestRD(x, rx);
    // Change x
    updateDestAD(x, rx);
    // Remove rx from other
    excludeReg(rx, x);
}

void CodeGenerate::updateDestRD(std::string x, std::string rx)
{
    getRegDscr(rx) -> clearSet(x);
}

void CodeGenerate::updateDestAD(std::string x, std::string rx)
{
    // Clear x
    findAddrDscr(x) -> clearSet(rx);
}

void CodeGenerate::genIntArithmTmpTmp(intmed_code_t &intmed_inst)
{
    // Select reg for x, y and z
    std::vector <RegDscr *> r_xyz = getReg(intmed_inst.val_type, intmed_inst.result, intmed_inst.arg1, intmed_inst.arg2);

    // Check y
    getVarInReg(intmed_inst.arg1, r_xyz[0], intmed_inst.val_type);

    // Check z
    getVarOrConstInReg(intmed_inst.arg2, r_xyz[1], intmed_inst.val_type);

    // Update x
    updateDest(intmed_inst.result.symbol, r_xyz[2] -> getRegName());

    std::string op = prefix_lut[intmed_inst.val_type] + inst_lut[att_lut[intmed_inst.op]] + suffix_lut[intmed_inst.val_type];
    appendAsm(op, r_xyz[2], r_xyz[0], r_xyz[1]);
}

// True Imm
void CodeGenerate::genIntArithmTmpImm(intmed_code_t &intmed_inst)
{
    // Select reg for x and y
    auto r_xy = getReg(intmed_inst.val_type, intmed_inst.result, intmed_inst.arg1);

    // Check y
    // If reg doesn't contain y, then we can issue load
    getVarInReg(intmed_inst.arg1, r_xy[0], intmed_inst.val_type);

    // Update x
    updateDest(intmed_inst.result.symbol, r_xy[1] -> getRegName());

    // Transform SUBI to ADDI
    std::string literal = trans_dec_lut[intmed_inst.val_type](intmed_inst.arg2.symbol);
    if (intmed_inst.op == SUB) {
        literal = "-" + literal;
    }
    std::string op = prefix_lut[intmed_inst.val_type] + inst_lut[ati_lut[intmed_inst.op]] + suffix_lut[intmed_inst.val_type];
    appendAsm(op, r_xy[1], r_xy[0], literal);
}

void CodeGenerate::genIntArithmImmTmp(intmed_code_t &intmed_inst)
{
    // Select reg for x, y and z
    auto r_xyz = getReg(intmed_inst.val_type, intmed_inst.result, intmed_inst.arg1, intmed_inst.arg2);

    // Check y
    getConstInReg(intmed_inst.arg1.symbol, r_xyz[0], intmed_inst.val_type);

    // Check z
    getVarInReg(intmed_inst.arg2, r_xyz[1], intmed_inst.val_type);

    // Update x
    updateDest(intmed_inst.result.symbol, r_xyz[2] -> getRegName());

    std::string op = prefix_lut[intmed_inst.val_type] + inst_lut[att_lut[intmed_inst.op]] + suffix_lut[intmed_inst.val_type];
    appendAsm(op, r_xyz[2], r_xyz[0], r_xyz[1]);
}

void CodeGenerate::genBranch(intmed_code_t &intmed_inst)
{
    std::string a = getVarOrConstInReg(intmed_inst.arg1, intmed_inst.val_type);
    std::string b = getVarOrConstInReg(intmed_inst.arg2, intmed_inst.val_type);
    appendAsm(inst_lut[branch_lut[intmed_inst.op]], a, b, intmed_inst.result.symbol);
}

void CodeGenerate::genJump(intmed_code_t &intmed_inst)
{
    appendAsm(inst_lut[RV_J], intmed_inst.result.symbol);
}

void CodeGenerate::genFloatSection()
{
    for (size_t i = 0; i < float_data.size(); i ++) {
        std::string label = FLOAT_SECTION_LABEL(i);
        auto & data = float_data[i];
        std::string word = ".word";
        if (data.type == double_type) {
            word = ".quad";
        }
        appendAsm(label + ":", false);
        appendAsm(word + inst_padding + data.dec_val, true);
    }
}
