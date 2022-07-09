#pragma once

#include <vector>
#include <fstream>

#include "postGrammarAnalysis.h"
#include "intermediateRepresentation.h"
#include "symbolTable.h"

// ---------------------------------NOTICE-----------------------------------
// 1. Insert can change the number of instructions. Use it carefully!

extern SymbolTable symbol_table;
extern PostGrammarAnalysis post_grammar_stage;
extern IntermediateRepr intermediate_stage;

typedef std::string reg_name_t;

static const std::string FLOAT_SECTION_PREFIX = ".L";

static const std::string inst_padding = "\t";
static const std::string inst_spacing = " ";
static const std::string target_arch = "\"rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0\"";
static const size_t stack_align_byte = 16;
static const char bp_id_prefix = '?';
static inline size_t GET_ALIGNED_BYTE(size_t byte, size_t align)
{
    return (byte + align - 1) / align * align;
}
static inline std::string FLOAT_SECTION_LABEL(size_t id)
{
    return FLOAT_SECTION_PREFIX + std::to_string(id);
}

static const std::vector <std::string> caller_saved_fix = {
    "t0", "t1", "t2", "t3", "t4", "t5", "t6",
    "a3", "a4", "a5", "a6", "a7", "a0", "a1", "a2"
};
static const std::string base_reg = "s11";
static const std::vector <std::string> callee_saved_fix = {
    "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10"
};
static const std::vector <std::string> caller_saved_float = {
    "ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7",
    "ft8", "ft9", "ft10", "ft11",
    "fa3", "fa4", "fa5", "fa6", "fa7", "fa0", "fa1", "fa2",
};
static const std::vector <std::string> callee_saved_float = {
    "fs0", "fs1", "fs2", "fs3", "fs4", "fs5",
    "fs6", "fs7", "fs8", "fs9", "fs10", "fs11",
};

typedef enum reg_type {
    REG_FIX,
    REG_FLOAT,
} reg_type_t;

/**
 * Definition of class register descriptor
 */
class RegDscr {
private:
    reg_name_t reg_name;  // Name of this register
    reg_type_t reg_type;  // Type of this register
    std::vector <std::string> var_list;  // Variables residing this register

public:
    /**
     * Constructor
     */
    RegDscr(reg_name_t reg_name, reg_type_t reg_type) {
        this -> reg_name = reg_name;
        this -> reg_type = reg_type;
    };
    /**
     * Destructor
     */
    ~RegDscr() {};
    /**
     * Get name of this register
     */
    reg_name_t & getRegName() {
        return reg_name;
    }
    reg_type_t & getRegType() {
        return reg_type;
    }
    std::vector <std::string> & getVarList() {
        return var_list;
    }
    /**
     * Append a variable to this descriptor
     */
    void appendVar(std::string var) {
        var_list.push_back(var);
    }
    /**
     * Search a variable residing in this decsriptor
     */
    bool findVar(std::string var) {
        auto iter = std::find(var_list.begin(), var_list.end(), var);
        return iter != var_list.end();
    }
    /**
     * Clear and set
     */
    void clearSet(std::string var) {
        var_list.clear();
        appendVar(var);
    }
};

typedef enum pos_prefix {
    NONE_POS,
    GLOBAL,
    STACK,
    REGISTER,
} pos_prefix_t;

typedef struct var_pos {
    pos_prefix_t prefix;
    std::string offset;

    bool operator == (const var_pos & another) {
        return (another.prefix == prefix) && (another.offset == offset);
    }
} var_pos_t;

class AddrDscr {
private:
    std::string var_name;  // Name of this var
    std::vector <var_pos_t> pos_list;  // Array of possible position
    var_pos_t origin_pos;  // Original space
    val_type_t dtype;  // data type

public:
    /**
     * Constructor
     */
    AddrDscr(std::string var_name, var_pos_t origin_pos, val_type_t dtype) {
        this -> var_name = var_name;
        this -> origin_pos = origin_pos;
        this -> dtype = dtype;
    };
    /**
     * Destructor
     */
    ~AddrDscr() {};
    /**
     * Get name of this var
     */
    std::string getVarName() {
        return var_name;
    }
    /**
     * Get data type
     */
    val_type_t getDType() {
        return dtype;
    }
    /**
     * Get origin pos
     */
    var_pos_t getOriginPos() {
        return origin_pos;
    }
    /**
     * Get all pos
     */
    std::vector <var_pos_t> & getAllPos() {
        return pos_list;
    }
    /**
     * Get a reg pos
     */
    bool getRegPos(std::string & name_to_fill) {
        for (auto iter = pos_list.begin(); iter != pos_list.end(); iter ++) {
            if (iter -> prefix == REGISTER) {
                name_to_fill = iter -> offset;
                return true;
            }
        }

        return false;
    }
    std::vector <std::string> getAllRegPos() {
        std::vector <std::string> ret;
        for (auto iter = pos_list.begin(); iter != pos_list.end(); iter ++) {
            if (iter -> prefix == REGISTER) {
                ret.push_back(iter -> offset);
            }
        }
        return ret;
    }
    /**
     * Add a possible pos as reg
     */
    void addPos(std::string reg) {
        addPos((var_pos_t) {REGISTER, reg});
    }
    /**
     * Add a possible pos
     */
    void addPos(pos_prefix_t prefix, off64_t offset) {
        addPos((var_pos_t) {prefix, std::to_string(offset)});
    }
    /**
     * Avoid duplicated pos
     */
    void addPos(var_pos_t pos) {
        auto iter = std::find(pos_list.begin(), pos_list.end(), pos);
        if (iter == pos_list.end()) {
            // Not found
            pos_list.push_back(pos);
        }
    }
    /**
     * Remove a position as reg
     */
    void removePos(std::string reg) {
        auto iter = std::find(pos_list.begin(), pos_list.end(), (var_pos_t) {REGISTER, reg});
        if (iter != pos_list.end()) {
            // If exists
            pos_list.erase(iter);
        }
    }
    /**
     * Clear and set
     */
    void clearSet(std::string reg) {
        pos_list.clear();
        addPos(reg);
    }
    void clearSet(var_pos_t pos) {
        pos_list.clear();
        addPos(pos);
    }
};

typedef enum asm_inst {
    RV_L,
    RV_S,
    RV_LI,
    RV_MV,
    RV_ADD,
    RV_ADDI,
    RV_SUB,
    RV_SUBI,
    RV_MUL,
    RV_DIV,
    RV_REM,
    RV_AND,
    RV_ANDI,
    RV_OR,
    RV_ORI,
    RV_XOR,
    RV_CALL,
    RV_JR,
    RV_J,
    RV_BEQ,
    RV_FEQ,
    RV_BNE,
    RV_FNE,
    RV_BLT,
    RV_FLT,
    RV_BGT,
    RV_FGT,
    RV_BLE,
    RV_FLE,
    RV_BGE,
    RV_FGE,
} asm_inst_t;

typedef struct asm_line {
    std::string op_info;  // opcode or info
    std::string pos1;
    std::string pos2;
    std::string pos3;
    std::string indent;

    asm_line(std::string op_info, bool indent = true, std::string pos1 = "", std::string pos2 = "", std::string pos3 = "") {
        this -> op_info = op_info;
        this -> pos1 = pos1;
        this -> pos2 = pos2;
        this -> pos3 = pos3;
        this -> indent = indent ? inst_padding : "";
    }
} asm_line_t;

/**
 * Definition of class code generation stage
 */
class CodeGenerate {
private:
    std::vector <asm_line_t> asm_array;  // Array of asm code
    std::vector <RegDscr *> current_reg_dscr;  // Current register descriptor array
    std::vector <AddrDscr *> addr_dscr;  // Current addr descriptor array
    std::vector <std::string> format_asm;  // Formatted asm, for output

    std::map <asm_inst_t, std::string> inst_lut {
        {RV_L, "l"},
        {RV_S, "s"},
        {RV_LI, "li"},
        {RV_MV, "mv"},
        {RV_ADD, "add"},
        {RV_ADDI, "addi"},
        {RV_SUB, "sub"},
        {RV_SUBI, "subi"},
        {RV_MUL, "mul"},
        {RV_DIV, "div"},
        {RV_REM, "rem"},
        {RV_AND, "and"},
        {RV_ANDI, "andi"},
        {RV_OR, "or"},
        {RV_ORI, "ori"},
        {RV_XOR, "xor"},
        {RV_CALL, "call"},
        {RV_JR, "jr"},
        {RV_J, "j"},
        {RV_BEQ, "beq"},
        {RV_FEQ, "feq"},
        {RV_BNE, "bne"},
        {RV_FNE, "fne"},
        {RV_BLT, "blt"},
        {RV_FLT, "flt"},
        {RV_BGT, "bgt"},
        {RV_FGT, "fgt"},
        {RV_BLE, "ble"},
        {RV_FLE, "fle"},
        {RV_BGE, "bge"},
        {RV_FGE, "fge"},
    };
    std::map <val_type_t, std::string> prefix_lut {
        {int_type, ""},
        {bool_type, ""},
        {float_type, "f"},
        {double_type, "f"},
    };
    std::map <val_type_t, std::string> suffix_lut {
        {int_type, "w"},
        {bool_type, ""},
        {float_type, ".s"},
        {double_type, ".d"},
    };
    std::map <val_type_t, std::string> mv_suf_lut {
        {int_type, ""},
        {bool_type, ""},
        {float_type, ".s"},
        {double_type, ".d"},
    };
    // For load and store
    std::map <val_type_t, std::string> ls_suf_lut {
        {int_type, "w"},
        {bool_type, "b"},
        {float_type, "w"},
        {double_type, "d"},
    };
    // Arithmetic temp temp
    std::map <intmed_op_t, asm_inst_t> att_lut {
        {ADD, RV_ADD},
        {SUB, RV_SUB},
        {MUL, RV_MUL},
        {DIV, RV_DIV},
        {MOD, RV_REM},
        {AND, RV_AND},
        {OR, RV_OR},
    };
    // Arithmetic temp imm
    std::map <intmed_op_t, asm_inst_t> ati_lut {
        {ADD, RV_ADDI},
        {SUB, RV_ADDI},
        {AND, RV_ANDI},
        {OR, RV_ORI},
    };
    std::map <val_type_t, std::string> asm_align_lut {
        {int_type, "2"},
        {bool_type, "0"},
        {float_type, "2"},
        {double_type, "3"},
    };
    std::map <val_type_t, std::string> asm_word_lut {
        {int_type, ".word"},
        {bool_type, ".byte"},
        {float_type, ".word"},
        {double_type, ".quad"},
    };
    // Branch
    std::map <intmed_op_t, asm_inst_t> branch_lut {
        {BEQ, RV_BEQ},
        {BNE, RV_BNE},
        {BLT, RV_BLT},
        {BGT, RV_BGT},
        {BLE, RV_BLE},
        {BGE, RV_BGE},
    };

    /**
     * Trans literal method
     */
    static std::string transIntLiteral(std::string literal) {
        return literal;
    }
    static std::string transBoolLiteral(std::string literal) {
        return (literal == "true") ? "1" : "0";
    }
    static std::string transFloatLiteral(std::string literal) {
        float value = std::stof(literal);
        int32_t * dec = (int32_t *)&value;
        return std::to_string(*dec);
    }
    static std::string transDoubleLiteral(std::string literal) {
        double value = std::stod(literal);
        int64_t * dec = (int64_t *)&value;
        return std::to_string(*dec);
    }
    std::string (*trans_dec_lut[max_val_type]) (std::string literal);

    /** Stack management */
    typedef struct bp_item {
        //size_t inst_idx;
        size_t offset;  // abs, with respect to s0.old
    } bp_item_t;
    std::vector <bp_item_t> bp_queue;  /** backpatch queue */
    size_t last_off;  /** last-time offset */
    std::map <val_type_t, size_t> align_lut {
        {int_type, 4},
        {bool_type, 1},
        {float_type, 4},
        {double_type, 8},
    };

    /** Floating-point section */
    typedef struct float_val {
        std::string dec_val;
        val_type_t type;

        float_val(std::string dec_val, val_type_t type) {
            this -> dec_val = dec_val;
            this -> type = type;
        }
        bool operator == (const float_val & value) {
            return (value.type == type) && (value.dec_val == dec_val);
        }
    } float_val_t;
    std::vector <float_val_t> float_data;
    std::map <val_type_t, reg_type_t> reg_type_lut {
        {int_type, REG_FIX},
        {bool_type, REG_FIX},
        {float_type, REG_FLOAT},
        {double_type, REG_FLOAT},
    };

public:
    /**
     * Constructor
     */
    CodeGenerate() {
        trans_dec_lut[int_type] = &transIntLiteral;
        trans_dec_lut[bool_type] = &transBoolLiteral;
        trans_dec_lut[float_type] = &transFloatLiteral;
        trans_dec_lut[double_type] = &transDoubleLiteral;
    };
    /**
     * Destructor
     */
    ~CodeGenerate() {};

    /**
     * Generate all asm
     */
    void genAsm();
    /**
     * Output to file
     */
    void outputToFile(std::string file_name);
    /**
     * Format asm inst for output
     */
    void formatAsm();

    /**
     * Append an assembly inst
     */
    void appendAsm(std::string line) {
        asm_array.push_back(asm_line_t(line));
    }
    void appendAsm(std::string line, bool indent) {
        asm_array.push_back(asm_line_t(line, indent));
    }
    void appendAsm(std::string op, std::string pos1, std::string pos2, std::string pos3) {
        asm_array.push_back(asm_line_t(op, true, pos1, pos2, pos3));
    }
    void appendAsm(std::string op, RegDscr * pos1, RegDscr * pos2, RegDscr * pos3) {
        appendAsm(op, pos1 -> getRegName(), pos2 -> getRegName(), pos3 -> getRegName());
    }
    void appendAsm(std::string op, RegDscr * pos1, RegDscr * pos2, std::string pos3) {
        appendAsm(op, pos1 -> getRegName(), pos2 -> getRegName(), pos3);
    }
    void appendAsm(std::string op, std::string pos1, std::string pos2) {
        asm_array.push_back(asm_line_t(op, true, pos1, pos2));
    }
    void appendAsm(std::string op, RegDscr * pos1, RegDscr * pos2) {
        appendAsm(op, pos1 -> getRegName(), pos2 -> getRegName());
    }
    void appendAsm(std::string op, RegDscr * pos1, std::string pos2) {
        appendAsm(op, pos1 -> getRegName(), pos2);
    }
    void appendAsm(std::string op, std::string pos1) {
        asm_array.push_back(asm_line_t(op, true, pos1));
    }
    void appendAsm(std::string op, RegDscr * pos1) {
        appendAsm(op, pos1 -> getRegName());
    }
    /**
     * Get current number of asm
     */
    size_t getAsmNum() {
        return asm_array.size();
    }
    /**
     * Insert an asm before certain line
     */
    void insertAsm(std::string op, std::string pos1, std::string pos2, std::string pos3, size_t line_num) {
        asm_array.insert(asm_array.begin() + line_num, asm_line_t(op, true, pos1, pos2, pos3));
    }
    void insertAsm(std::string op, std::string pos1, std::string pos2, size_t line_num) {
        insertAsm(op, pos1, pos2, "", line_num);
    }
    /**
     * getReg method, for Rx, Ry and Rz
     */
    std::vector <RegDscr *> getReg(val_type_t dtype, intmed_arg_t dest, intmed_arg_t src1, intmed_arg_t src2);
    /**
     * Get reg for Rx and Ry/z
     */
    std::vector <RegDscr *> getReg(val_type_t dtype, intmed_arg_t dest, intmed_arg_t src);
    /**
     * getReg method, for Rx
     */
    RegDscr * getReg(val_type_t dtype, std::string dest);
    /**
     * Get reg for src
     */
    RegDscr * getRegForSrc(val_type_t dtype, std::string src, std::string x, bool cover_x = false);
    /**
     * Get reg for dest
     */
    RegDscr * getRegForDest(val_type_t dtype, std::string dest);
    /**
     * Generate load to reg
     */
    void genLoadToReg(intmed_arg_t var, RegDscr * reg, val_type_t dtype);
    /**
     * Generate move
     */
    void genMoveToReg(std::string dest, std::string src, val_type_t dtype);
    /**
     * Generate store from register
     */
    void genStoreFromReg(reg_name_t reg, std::string var);
    void genStoreFromReg(reg_name_t reg, AddrDscr * descriptor);
    /**
     * Save temp to stack, alloc space if needed
     */
    void saveToStack(reg_name_t reg, std::string var, val_type_t dtype);
    /**
     * Get variable in a certain reg
     */
    void getVarInReg(intmed_arg_t var, RegDscr * reg, val_type_t dtype);
    /**
     * Get var in reg, but not specified
     */
    std::string getVarInReg(intmed_arg_t var, val_type_t dtype);
    /**
     * Get const in reg
     */
    void getConstInReg(std::string imm, RegDscr * reg, val_type_t dtype);
    /**
     * Get const in reg, but not specified
     */
    std::string getConstInReg(intmed_arg_t imm, val_type_t dtype);
    /**
     * Get var or const in reg
     */
    void getVarOrConstInReg(intmed_arg_t var, RegDscr * reg, val_type_t dtype);
    /**
     * With allocation
     */
    std::string getVarOrConstInReg(intmed_arg_t var, val_type_t dtype);
    /**
     * Remove Rx from addr_dscr of any var other than x
     */
    void excludeReg(std::string rx, std::string x) {
        for (auto iter = addr_dscr.begin(); iter != addr_dscr.end(); iter ++) {
            if (((*iter) -> getVarName()) != x) {
                (*iter) -> removePos(rx);
            }
        }
    }
    /**
     * Get current reg descriptor
     */
    std::vector <RegDscr *> & getAllRegDscr() {
        return current_reg_dscr;
    }
    /**
     * Get a reg dscr
     */
    RegDscr * getRegDscr(std::string name) {
        for (auto iter = current_reg_dscr.begin(); iter != current_reg_dscr.end(); iter ++) {
            if ((*iter) -> getRegName() == name) {
                return *iter;
            }
        }

        return NULL;
    }
    /**
     * Get an empty reg dscr
     */
    RegDscr * getEmptyRD(val_type_t dtype) {
        for (auto iter = current_reg_dscr.begin(); iter != current_reg_dscr.end(); iter ++) {
            if (((*iter) -> getVarList()).size() == 0 && ((*iter) -> getRegType()) == reg_type_lut[dtype]) {
                return *iter;
            }
        }

        return NULL;
    }
    /**
     * Find a candidate reg
     */
    RegDscr * candidReg(val_type_t dtype);
    /**
     * Move variables out from a reg
     */
    void moveVarOut(RegDscr * reg, std::string x, bool cover_x = false);
    /**
     * Alloc new addr dscr
     */
    AddrDscr * allocAD(std::string var, var_pos_t pos, val_type_t dtype) {
        AddrDscr * ret = new AddrDscr(var, pos, dtype);
        addr_dscr.push_back(ret);
        return ret;
    }
    /**
     * Update AD and RD for copy
     */
    void copyDscr(std::string dest, std::string src);
    /**
     * Clear non-global AD
     */
    void clearLocalAD() {
        for (auto iter = addr_dscr.begin(); iter != addr_dscr.end();) {
            if (((*iter) -> getOriginPos()).prefix != GLOBAL) {
                addr_dscr.erase(iter);
                delete *iter;
                iter = addr_dscr.begin();
            } else {
                iter ++;
            }
        }
    }
    /**
     * Find an addr dscr
     */
    AddrDscr * findAddrDscr(std::string name) {
        for (auto iter = addr_dscr.begin(); iter != addr_dscr.end(); iter ++) {
            if ((*iter) -> getVarName() == name) {
                return *iter;
            }
        }

        return NULL;
    }
    /**
     * Get reg from addr dscr
     */
    std::string checkRegForVar(std::string var) {
        auto descriptor = findAddrDscr(var);
        std::string reg_name = "";
        if (descriptor != NULL) {
            // Not allocated
            descriptor -> getRegPos(reg_name);
        }
        return reg_name;
    }
    std::vector <std::string> getRegOfVar(std::string var) {
        auto descriptor = findAddrDscr(var);
        return descriptor -> getAllRegPos();
    }
    /**
     * Update status of dest operand
     */
    void updateDest(std::string x, std::string rx);
    /**
     * Update dest addr dscr
     */
    void updateDestAD(std::string x, std::string rx);
    /**
     * Update dest reg dscr
     */
    void updateDestRD(std::string x, std::string rx);
    /**
     * Generate code for arithmetic/logic inst `x = y op z`
     * include: ADD, SUB, MUL, DIV, MOD, AND, OR
     */
    void genIntArithmTmpTmp(intmed_code_t &intmed_inst);
    /**
     * Generate code for arithmetic/logic inst `x = y op z`
     * in which z is imm
     * include: ADD, SUB, AND, OR
     */
    void genIntArithmTmpImm(intmed_code_t &intmed_inst);
    /**
     * `x = y op z` of format t = i op t
     */
    void genIntArithmImmTmp(intmed_code_t &intmed_inst);
    /**
     * `x = y op z` of format t = i op i
     */
    void genIntArithmImmImm(intmed_code_t &intmed_inst) {};
    /**
     * Deserialize
     */
    std::vector <std::string> splitValList(std::string list, char split = ',') {
        std::vector <std::string> ret;
        auto head = list.begin();
        for (;;) {
            auto tail = std::find(head, list.end(), split);
            ret.push_back(list.substr(head - list.begin(), tail - head));

            if (tail == list.end()) {
                break;
            } else {
                head = tail;
            }
        }

        return ret;
    };
    /**
     * Generate global var
     */
    void genGlobVar(intmed_code_t &intmed_inst);
    /**
     * Generate asm header
     */
    void genAsmHead(std::string file_name);
    /**
     * Generate function header
     */
    void genFuncHead(intmed_code_t &intmed_inst);
    /**
     * Move retval
     */
    void moveRetVal(intmed_code_t &intmed_inst);
    /**
     * Generate function end
     */
    void genFuncEnd(intmed_code_t &intmed_inst, size_t begin_inst);
    /**
     * Generate function parameters
     */
    void genFuncParam(intmed_code_t &intmed_inst);
    /**
     * Generate function call
     */
    void genFuncCall(intmed_code_t &intmed_inst);
    /**
     * Backpatch stack pointer
     */
    void backPatchSP(size_t begin_inst, size_t end_inst) {
        for (size_t i = begin_inst; i < end_inst; i ++) {
            std::string & pos2 = asm_array[i].pos2;
            // Revise pos2 (for load and store)
            if (pos2[0] == bp_id_prefix) {
                size_t id = std::stoul(pos2.substr(1, pos2.length() - 1));
                size_t off = bp_queue[id].offset;
                pos2 = "-" + std::to_string(off) + "(s0)";
            }
        }
    }
    /**
     * Generate stack init
     */
    void genStackInit(intmed_code_t &intmed_inst);
    /**
     * Clear stack
     */
    void clearStack(size_t offset = 16) {
        bp_queue.clear();
        last_off = offset;
    }
    /**
     * Register a position from stack
     * @return id
     */
    std::string stackRegister(size_t byte, size_t align) {
        size_t new_high = GET_ALIGNED_BYTE(last_off, align);
        size_t new_low = new_high + byte;
        auto bp_id = bp_queue.size();
        bp_queue.push_back((bp_item_t) {new_low});
        last_off = new_low;
        return bp_id_prefix + std::to_string(bp_id);
    }
    /**
     * Alloc a position from stack
     */
    AddrDscr * stackAlloc(std::string var, size_t total_size, val_type_t dtype) {
        std::string stack_pos = stackRegister(total_size, align_lut[dtype]);
        auto ad = allocAD(var, (var_pos_t) {STACK, stack_pos}, dtype);
        return ad;
    }
    /**
     * Get current stack offset
     */
    size_t & getStackOff() {
        return last_off;
    }
    /**
     * Generate load from stack
     */
    void genLoadFromStack(AddrDscr * var, RegDscr * reg, val_type_t dtype);
    /**
     * Generate load from global
     */
    void genLoadFromGlob(AddrDscr * var, RegDscr * reg, val_type_t dtype);
    /**
     * Set descriptor for function
     */
    void setDscrForFunc(std::string func_name);
    /**
     * Clear descriptor for call, save caller-saved registers
     */
    void clearDscrForCall();
    /**
     * Clear all RD
     */
    void clearAllRD() {
        for (size_t i = 0; i < current_reg_dscr.size(); i ++) {
            delete current_reg_dscr[i];
        }
        current_reg_dscr.clear();
    }
    /**
     * Remove reg from all AD
     */
    void removeRegFromAll(std::string reg);
    /**
     * Alloc new RD list, register allocation included
     */
    void allocRD();
    /**
     * Generate load to temp
     */
    void genLoadToTmp(intmed_code_t &intmed_inst);
    /**
     * Generate store from tmp
     */
    void genStoreFromTmp(intmed_code_t &intmed_inst);
    /**
     * Generate branch inst
     */
    void genBranch(intmed_code_t &intmed_inst);
    /**
     * Generate jump
     */
    void genJump(intmed_code_t &intmed_inst);
    /**
     * Generate label
     */
    void genLabel(std::string label);
    /**
     * Alloc a new float_val
     */
    std::string getNewFloat(std::string dec_val, val_type_t dtype) {
        size_t id = float_data.size();
        float_data.push_back(float_val_t(dec_val, dtype));
        return FLOAT_SECTION_LABEL(id);
    }
    /**
     * Find a float value, return a label
     */
    std::string findFloatVal(std::string dec_val, val_type_t dtype) {
        std::string ret = "";
        auto iter = std::find(float_data.begin(), float_data.end(), float_val_t(dec_val, dtype));
        if (iter != float_data.end()) {
            ret = FLOAT_SECTION_LABEL(iter - float_data.begin());
        }
        return ret;
    }
    /**
     * Load float imm to reg
     */
    void loadFloatImm(std::string reg, std::string dec_val, val_type_t dtype);
    /**
     * Generate float section
     */
    void genFloatSection();
};
