#include "intermediateRepresentation.h"
#include "postGrammarAnalysis.h"

/************************ NOTICE ********************
1. relExp for bool is temporarily not supported


****************************************************/

/// @author dhk
void IntermediateRepr::printIR(int ir_index)
{
    auto code = getACode(ir_index);
    std::cout << code.result.symbol << " = ";
    std::cout << op_to_string[code.op] << ": ";
    std::cout << code.arg1.symbol << ", ";
    std::cout << code.arg2.symbol << " " << TYPE_SUFFIX;
    std::cout << post_grammar_stage.val_type_to_str[code.val_type] << std::endl;
}

void IntermediateRepr::printAllIR()
{
    size_t num_code = getIntmedNum();
    for(size_t i = 0; i < num_code; i ++){
        auto label_before = label_array.find(i);
        if(label_before != label_array.end()){
            // There is a label before this code
            std::cout << (label_before -> second).name << std::endl;
        }
        printIR(i);
    }
}

void IntermediateRepr::enterCompUnit(CACTParser::CompUnitContext * ctx)
{
    // Initialization for intermidiate geneartion
    current_scope = symbol_table.scope_root;
    // Encode scope
    encodeScope();
    // Rename as symbolic names
    symtabRename();
}

void IntermediateRepr::encodeScope()
{
    scope_id = 0;
    visitScope(current_scope);
}

// DFS
void IntermediateRepr::visitScope(scope_node_t * scope)
{
    encode_scope[scope] = scope_id ++;
    auto & child = scope -> children;
    for (size_t i = 0; i < child.size(); i ++) {
        visitScope(child[i]);
    }
}

// Rename duplicated name in symbol table
void IntermediateRepr::symtabRename()
{
    // Use iterator to visit this map
    auto iter = symbol_table.var_symbol_table.begin();
    auto end = symbol_table.var_symbol_table.end();
    for(; iter != end; iter ++) {
        (iter -> second).var_name = RENAME_VAR((iter -> first).var_name, (iter -> first).scope_ptr);
    }
}

void IntermediateRepr::exitCompUnit(CACTParser::CompUnitContext * ctx)
{
    printAllIR();
    //symtabRename();
}

void IntermediateRepr::enterBType(CACTParser::BTypeContext * ctx)
{
    //std::cout << ctx -> btype_val_type << std::endl;
}

// LD for STACK_ALLOC is necessary!!!
template <typename T_ctx>
void IntermediateRepr::exitConstAndVarDef(T_ctx &ctx, std::string value_list)
{
    intmed_op_t op;
    if (current_scope == symbol_table.scope_root) {
        // global
        op = G_ALLOC;
    }else{
        // local
        op = D_ALLOC;
    }
    std::string id = ctx -> Ident() -> getText();
    var_symbol_item_t * var_item = &(symbol_table.var_symbol_table[(name_in_scope){id, current_scope}]);
    std::string temp = newTemp(var_item -> var_type, var_item -> num_items, var_item -> is_array, false, var_item);
    appendIntmed(
        op,
        temp,
        var_item -> var_type,
        intmed_arg_t(var_item -> var_name, var_item, false, var_item -> num_items),
        value_list
    );
}

template <typename T_ctx>
void IntermediateRepr::exitConstAndVarDefInit(T_ctx &ctx)
{
    exitConstAndVarDef(ctx, ctx -> constInitVal() -> value_list);
}

/// @author dhk
void IntermediateRepr::exitConstDef_empty(CACTParser::ConstDef_emptyContext * ctx)
{
    exitConstAndVarDef(ctx);
}

void IntermediateRepr::exitConstDef_init(CACTParser::ConstDef_initContext * ctx)
{
    exitConstAndVarDefInit(ctx);
}

void IntermediateRepr::exitVarDef_empty(CACTParser::VarDef_emptyContext * ctx)
{
    exitConstAndVarDef(ctx);
}

void IntermediateRepr::exitVarDef_init(CACTParser::VarDef_initContext * ctx)
{
    exitConstAndVarDefInit(ctx);
}

void IntermediateRepr::exitConstExp_single(CACTParser::ConstExp_singleContext * ctx)
{
    ctx -> value_list = ctx -> constExp() -> const_value;
}

void IntermediateRepr::exitConstExp_array(CACTParser::ConstExp_arrayContext * ctx)
{
    // Strip spaces
    std::string value_list = (ctx -> constExp())[0] -> const_value;
    size_t num_items = ctx -> num_items; // >=1
    for(size_t i = 1; i < num_items; i ++){
        value_list += "," + ((ctx -> constExp())[i]) -> const_value;
    }
    ctx -> value_list = value_list;
}

void IntermediateRepr::exitFuncDef(CACTParser::FuncDefContext * ctx)
{
    // Check the last code
    auto & last_code = getACode(getIntmedNum() - 1);

    // Attach and End
    size_t num_code = getIntmedNum();
    attachLabel(current_func_end, num_code);
    appendIntmed(FUNC_END, ctx -> funcHeader() -> Ident() -> getText(), void_type);
}

void IntermediateRepr::enterFuncHeader(CACTParser::FuncHeaderContext * ctx)
{
    auto func_item = &(symbol_table.func_symbol_table[ctx -> Ident() -> getText()]);
    // Notice: which code is next code?
    //func_item -> which_label = newLabel();
    current_func_end = newLabel();
    appendIntmed(FUNC_BEGIN, func_item -> func_name, func_item -> ret_type, std::to_string((func_item -> fparam_list).size()));
}

void IntermediateRepr::enterBlock(CACTParser::BlockContext * ctx)
{
    // Enter this block's scope
    current_scope = (current_scope -> children)[ctx -> index_in_father];
}

void IntermediateRepr::exitBlock(CACTParser::BlockContext * ctx)
{
    current_scope = current_scope -> father;
}

// stmt
// ---------------------------------------------------------------
void IntermediateRepr::exitStmt_assign(CACTParser::Stmt_assignContext * ctx)
{
    std::string exp_name = ctx -> exp() -> result_name;

    std::string lval_name = ctx -> lVal() -> Ident() -> getText();
    var_symbol_item_t * symtab_item = &(symbol_table.findVarInTab(lval_name, current_scope) -> second);
    val_type_t lval_type = symtab_item -> var_type;
    appendIntmed(
        ST,
        exp_name,
        lval_type,
        intmed_arg_t(symtab_item -> var_name, symtab_item, symtab_item -> is_const, symtab_item -> num_items)
    );
}

void IntermediateRepr::enterLab(CACTParser::LabContext * ctx)
{
    size_t num_code = getIntmedNum();
    attachLabel(ctx -> use_label, num_code);
}

void IntermediateRepr::enterGo(CACTParser::GoContext * ctx)
{
    appendIntmed(J, ctx -> goto_label, void_type);
}

// Here we only consider one `if`
void IntermediateRepr::enterStmt_if(CACTParser::Stmt_ifContext * ctx)
{
    std::string if_end = newLabel();
    ctx -> nextlist = if_end;
    if((ctx -> stmt()).size() > 1){   // 2 stmt
        std::string B_true = newLabel();
        std::string B_false = newLabel();
        ctx -> cond() -> truelist = B_true;
        ctx -> cond() -> falselist = B_false;
        ctx -> stmt()[0] -> nextlist = if_end;
        ctx -> stmt()[1] -> nextlist = if_end;

        (ctx -> lab())[0] -> use_label = B_true;
        (ctx -> lab())[1] -> use_label = B_false;
        ctx -> go() -> goto_label = if_end;
    }
    else{                           // 1 stmt
        std::string B_true = newLabel();
        ctx -> cond() -> truelist = B_true;
        ctx -> cond() -> falselist = if_end;
        ctx -> stmt()[0] -> nextlist = if_end;

        (ctx -> lab())[0] -> use_label = B_true;
    }
}

void IntermediateRepr::exitStmt_if(CACTParser::Stmt_ifContext * ctx)
{
    size_t next_code = getIntmedNum();
    attachLabel(ctx -> nextlist, next_code);
}

void IntermediateRepr::enterStmt_while(CACTParser::Stmt_whileContext * ctx)
{
    std::string begin = newLabel();
    std::string end = newLabel();
    std::string B_true = newLabel();
    ctx -> cond() -> truelist = B_true;
    ctx -> cond() -> falselist = end;
    ctx -> stmt() -> nextlist = begin;

    (ctx -> lab())[0] -> use_label = begin;
    (ctx -> lab())[1] -> use_label = B_true;
    ctx -> go() -> goto_label = begin;

    ctx -> while_begin = begin;
    ctx -> while_end = end;
    ctx -> nextlist = end;
}

void IntermediateRepr::exitStmt_while(CACTParser::Stmt_whileContext * ctx)
{
    size_t next_code = getIntmedNum();
    attachLabel(ctx -> nextlist, next_code);
}

void IntermediateRepr::enterStmt_break(CACTParser::Stmt_breakContext * ctx)
{
    std::string target = ctx -> while_end;
    appendIntmed(J, target, void_type);
}

void IntermediateRepr::enterStmt_continue(CACTParser::Stmt_continueContext * ctx){
    std::string target = ctx -> while_begin;
    appendIntmed(J, target, void_type);
}

/// @author dhk
// Notice: when to dealloc?
void IntermediateRepr::exitStmt_return(CACTParser::Stmt_returnContext * ctx)
{
    var_symbol_item_t * item = NULL;
    bool is_const = ctx -> exp() -> is_const;
    std::string result_name = ctx -> exp() -> result_name;
    appendIntmed(
        RETURN,
        intmed_arg_t(""),
        (val_type_t)(ctx -> exp() -> exp_val_type),
        intmed_arg_t(result_name, NULL, is_const, 0)
        );

    appendIntmed(J, current_func_end, void_type);
}

void IntermediateRepr::exitExp_add(CACTParser::Exp_addContext * ctx)
{
    ctx -> result_name = ctx -> addExp () -> result_name;
}

void IntermediateRepr::exitExp_bool(CACTParser::Exp_boolContext * ctx)
{
    ctx -> result_name = ctx -> BoolConst() -> getText();
}

void IntermediateRepr::exitPrimaryExp_exp(CACTParser::PrimaryExp_expContext * ctx)
{
    ctx -> result_name = ctx -> exp() -> result_name;
}

void IntermediateRepr::enterPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * ctx)
{
    //ctx -> is_const = false;
}

void IntermediateRepr::exitPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * ctx)
{
    bool is_array = ctx -> lVal() -> is_array;
    bool is_const = ctx -> is_const;
    size_t num_items = ctx -> lVal() -> num_items;
    std::string var_name = ctx -> lVal() -> Ident() -> getText();
    auto symtab_item = &((symbol_table.findVarInTab(var_name, current_scope)) -> second);
    val_type_t dtype = (val_type_t)(ctx -> lVal() -> lval_type);
    std::string temp = newTemp(dtype, num_items, is_array, false, symtab_item);
    std::string offset_name = "";
    auto exp = ctx -> lVal() -> exp();
    if (exp) {
        offset_name = exp -> result_name;
    }
    appendIntmed(LD, intmed_arg_t(temp, NULL, false), dtype, intmed_arg_t(symtab_item -> var_name, NULL, false), offset_name);

    ctx -> result_name = temp;
}

void IntermediateRepr::exitPrimaryExp_num(CACTParser::PrimaryExp_numContext * ctx)
{
    ctx -> result_name = ctx -> number() -> getText();
}

void IntermediateRepr::exitUnaryExp_primary(CACTParser::UnaryExp_primaryContext * ctx)
{
    ctx -> result_name = ctx -> primaryExp() -> result_name;
}

void IntermediateRepr::exitUnaryExp_call(CACTParser::UnaryExp_callContext * ctx)
{
    // Notice: for void?
    std::string func_name = ctx -> Ident() -> getText();
    size_t num_arg = (symbol_table.func_symbol_table)[func_name].fparam_list.size();
    val_type_t func_val = (symbol_table.func_symbol_table)[func_name].ret_type;
    std::string ret_temp = newTemp(func_val, 0, false, false, NULL);

    appendIntmed(CALL, ret_temp, func_val, func_name, std::to_string(num_arg));

    ctx -> result_name = ret_temp;
}

void IntermediateRepr::exitUnaryExp_uop(CACTParser::UnaryExp_uopContext * ctx)
{
    std::string uop = ctx -> unaryOp() -> getText();
    std::string uexp_result = ctx -> unaryExp() -> result_name;
    if(uop == "+"){
        ctx -> result_name = uexp_result;
    }else if(uop == "!"){
        // Not for array
        std::string result = newTemp(bool_type, ctx -> num_items, false, false, NULL);
        appendIntmed(NOT, result, bool_type, uexp_result);
        ctx -> result_name = result;
    }else{
        // Take neg
        val_type_t uexp_type = (val_type_t)(ctx -> unaryExp() -> unary_exp_val_type);
        intmed_op_t op;
        bool is_array = ctx -> unaryExp() -> is_array;
        if(is_array){
            op = NEG_V;
        }else{
            op = NEG;
        }
        std::string result = newTemp(uexp_type, ctx -> num_items, is_array, false, NULL);
        appendIntmed(op, result, uexp_type, uexp_result);
        ctx -> result_name = result;
    }
}

void IntermediateRepr::exitFuncRParams(CACTParser::FuncRParamsContext * ctx)
{
    size_t num_params = (ctx -> exp()).size();
    for(size_t i = 0; i < num_params; i ++){
        auto exp = (ctx -> exp())[i];
        appendIntmed(
            PARAM,
            intmed_arg_t(exp -> result_name, NULL, exp -> is_const),
            (val_type_t)(exp -> exp_val_type),
            std::to_string(i)
        );
    }
}

void IntermediateRepr::exitConstExp_num(CACTParser::ConstExp_numContext * ctx)
{
    ctx -> const_value = ctx -> number() -> number_value;
}

void IntermediateRepr::exitConstExp_bool(CACTParser::ConstExp_boolContext * ctx)
{
    ctx -> const_value = ctx -> BoolConst() -> getText();
}

void IntermediateRepr::exitNumber_int(CACTParser::Number_intContext * ctx)
{
    ctx -> number_value = ctx -> getText();
}

void IntermediateRepr::exitNumber_double(CACTParser::Number_doubleContext * ctx)
{
    ctx -> number_value = ctx -> getText();
}

void IntermediateRepr::exitNumber_float(CACTParser::Number_floatContext * ctx)
{
    ctx -> number_value = ctx -> getText();
}

void IntermediateRepr::enterCond(CACTParser::CondContext * ctx)
{
    ctx -> lOrExp() -> truelist = ctx -> truelist;
    ctx -> lOrExp() -> falselist = ctx -> falselist;
}

void IntermediateRepr::exitMulExp_unary(CACTParser::MulExp_unaryContext * ctx)
{
    ctx -> result_name = ctx -> unaryExp() -> result_name;
}

void IntermediateRepr::exitMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * ctx)
{
    intmed_op_t op;
    val_type_t mexp_type = (val_type_t)(ctx -> unaryExp() -> unary_exp_val_type);
    std::string mexp_result = ctx -> mulExp() -> result_name;
    std::string uexp_result = ctx -> unaryExp() -> result_name;

    std::string mulop = ctx -> mulOp() -> getText();
    bool is_array = ctx -> unaryExp() -> is_array;

    switch(mulop[0]){
        case '*': op = (is_array ? MUL_V : MUL);    break;
        case '/': op = (is_array ? DIV_V : DIV);    break;
        case '%': op = (is_array ? MOD_V : MOD);    break;
    }

    std::string result = newTemp(mexp_type, ctx -> num_items, ctx -> is_array, ctx -> is_const, NULL);
    appendIntmed(op, result, mexp_type, intmed_arg_t(mexp_result, NULL, ctx -> mulExp() -> is_const), intmed_arg_t(uexp_result, NULL, ctx -> unaryExp() -> is_const));
    ctx -> result_name = result;
}

void IntermediateRepr::exitAddExp_mul(CACTParser::AddExp_mulContext * ctx)
{
    ctx -> result_name = ctx -> mulExp() -> result_name;
}

void IntermediateRepr::exitAddExp_add_mul(CACTParser::AddExp_add_mulContext * ctx)
{
    intmed_op_t op;
    val_type_t aexp_type = (val_type_t)(ctx -> mulExp() -> mul_exp_val_type);
    std::string aexp_result = ctx -> addExp() -> result_name;
    std::string mexp_result = ctx -> mulExp() -> result_name;

    std::string addop = ctx -> addOp() -> getText();
    bool is_array = ctx -> mulExp() -> is_array;

    switch(addop[0]){
        case '+': op = is_array ? ADD_V : ADD;    break;
        case '-': op = is_array ? SUB_V : SUB;    break;
    }

    std::string result = newTemp(aexp_type, ctx -> num_items, ctx -> is_array, ctx -> is_const, NULL);
    appendIntmed(op, result, aexp_type, intmed_arg_t(aexp_result, NULL, ctx -> addExp() -> is_const), intmed_arg_t(mexp_result, NULL, ctx -> mulExp() -> is_const));
    ctx -> result_name = result;
}

void IntermediateRepr::exitRelExp_add(CACTParser::RelExp_addContext * ctx)
{
    ctx -> result_name = ctx -> addExp() -> result_name;
}

void IntermediateRepr::exitRelExp_rel_add(CACTParser::RelExp_rel_addContext * ctx)
{
    intmed_op_t op1;
    intmed_op_t op2 = J;
    std::string target1 = ctx -> truelist, target2 = ctx -> falselist;
    val_type_t aexp_type = (val_type_t)(ctx -> addExp() -> add_exp_val_type);
    std::string rexp_result = ctx -> relExp() -> result_name;
    std::string aexp_result = ctx -> addExp() -> result_name;

    std::string relop = ctx -> relOp() -> getText();

    switch(relop[0]){
        case '<': op1 = relop[1] == '=' ? BLE : BLT;    break;
        case '>': op1 = relop[1] == '=' ? BGE : BGT;    break;
    }

    appendIntmed(
        op1,
        target1,
        aexp_type,
        intmed_arg_t(rexp_result, NULL, ctx -> relExp() -> is_const),
        intmed_arg_t(aexp_result, NULL, ctx -> addExp() -> is_const)
    );

    appendIntmed(op2, target2, void_type);

    // Here we only consider simple cases
}

void IntermediateRepr::exitRelExp_bool(CACTParser::RelExp_boolContext * ctx)
{
    intmed_op_t op = J;
    ctx -> result_name = ctx -> BoolConst() -> getText();
    std::string target = (ctx -> BoolConst() -> getText() == "true") ? ctx -> truelist : ctx -> falselist;
    appendIntmed(op, target, void_type);
}

void IntermediateRepr::enterEqExp(CACTParser::EqExpContext * ctx)
{
    if((ctx -> eqExp()) == NULL){
        ctx -> relExp() -> truelist = ctx -> truelist;
        ctx -> relExp() -> falselist = ctx -> falselist; 
    }
}

// Here we only consider `a == b`
void IntermediateRepr::exitEqExp(CACTParser::EqExpContext * ctx){
    // relExp
    if((ctx -> eqExp()) == NULL){
        ctx -> result_name = ctx -> relExp() -> result_name;
        ctx -> is_const = ctx -> relExp() -> is_const;
    }
    // eqExp eqOp relExp
    else{
        intmed_op_t op1;
        intmed_op_t op2 = J;
        std::string target1 = ctx -> truelist, target2 = ctx -> falselist;
        val_type_t rexp_type = (val_type_t)(ctx -> relExp() -> rel_exp_val_type);
        std::string eexp_result = ctx -> eqExp() -> result_name;
        std::string rexp_result = ctx -> relExp() -> result_name;

        std::string relop = ctx -> eqOp() -> getText();

        switch(relop[0]){
            case '=': op1 = BEQ;    break;
            case '!': op1 = BNE;    break;
        }

        appendIntmed(
            op1,
            target1,
            rexp_type,
            intmed_arg_t(eexp_result, NULL, ctx -> eqExp() -> is_const),
            intmed_arg_t(rexp_result, NULL, ctx -> relExp() -> is_const)
        );

        appendIntmed(op2, target2, void_type);
    }
}

void IntermediateRepr::enterLAndExp(CACTParser::LAndExpContext * ctx)
{
    // eqExp
    if(!ctx->lAndExp()){
        ctx -> eqExp() -> truelist = ctx -> truelist;
        ctx -> eqExp() -> falselist = ctx -> falselist;
    }
    // lAndExp '&&' eqExp
    else{
        std::string B1_true = newLabel();
        ctx -> lAndExp() -> truelist = B1_true;
        ctx -> lAndExp() -> falselist = ctx -> falselist;
        ctx -> eqExp() -> truelist = ctx -> truelist;
        ctx -> eqExp() -> falselist = ctx -> falselist;

        // Attach label
        ctx -> lab() -> use_label = B1_true;
    }
}

void IntermediateRepr::exitLAndExp(CACTParser::LAndExpContext * ctx){
    // eqExp
    if(!ctx->lAndExp()){
        ctx -> result_name = ctx -> eqExp() -> result_name;
        ctx -> is_const = ctx -> eqExp() -> is_const;
    }
    // lAndExp '&&' eqExp
    else{
        ;
    }
}

void IntermediateRepr::enterLOrExp(CACTParser::LOrExpContext * ctx)
{
    // lAndExp
    if(!ctx->lOrExp()){
        ctx -> lAndExp() -> truelist = ctx -> truelist;
        ctx -> lAndExp() -> falselist = ctx -> falselist;
    }
    // lOrExp '||' lAndExp
    else{
        ctx -> lOrExp() -> truelist = ctx -> truelist;
        std::string B1_false = newLabel();
        ctx -> lOrExp() -> falselist = B1_false;
        ctx -> lAndExp() -> truelist = ctx -> truelist;
        ctx -> lAndExp() -> falselist = ctx -> falselist;

        ctx -> lab() -> use_label = B1_false;
    }
}

void IntermediateRepr::exitLOrExp(CACTParser::LOrExpContext * ctx){
    // lAndExp
    if(!ctx->lOrExp()){
        ctx -> result_name = ctx -> lAndExp() -> result_name;
        ctx -> is_const = ctx -> lAndExp() -> is_const;
    }
    // lOrExp '||' lAndExp
    else{
        ;
    }
}