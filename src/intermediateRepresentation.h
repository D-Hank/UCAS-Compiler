#pragma once

#include "../grammar/CACTBaseListener.h"

#include <vector>

#include "postGrammarAnalysis.h"
#include "symbolTable.h"

#define ALIGN "4"
#define TEMP_SUFFIX "%"
#define LABEL_SUFFIX "L"
//#define FUNC_SUFFIX "@"
#define GLOBAL_SUFFIX "#"
#define TYPE_SUFFIX "@"

static inline std::string bool_to_int(std::string value)
{
    return (value == "true") ? "0U" : "0xFFFFFFFFU";
}

extern SymbolTable symbol_table;

// Notice: arrange the stack when CALL
// Pass the parameter when PARAM
typedef enum intmed_op
{
    LD,         // LD, result, int, base, index/null
    ST,         // ST, result, int, base, index/null
    ADD,        // ADD, result, int, arg1, arg2
    ADD_V,      // ADD_V, result, int, array1, array2
    SUB,
    SUB_V,
    NEG,        // NEG, result, int, source, null
    NEG_V,
    NOT,        // NOT, result, int, source, null
    MUL,
    MUL_V,
    DIV,
    DIV_V,
    MOD,
    MOD_V,
    AND,
    OR,
    CALL,       // CALL, result, int, name, argc
    RETURN,     // RETURN, null, int, result, null
    PARAM,      // PARAM, arg, int, which, null
    FUNC_BEGIN, // BEGIN, name, type, num_arg, null
    FUNC_END,   // END, name, null, null, null
    D_ALLOC,    // D_ALLOC, t1, int, var_name, init_values
    G_ALLOC,    // G_ALLOC, t1, int, var_name, init_values
    BEQ,
    BNE,
    BLT,        // BLT, target, float, a, b
    BGT,
    BLE,
    BGE,
    J,          //J, target, void, null, null
} intmed_op_t;

typedef struct intmed_arg {
    std::string symbol;  // symbolic name
    var_symbol_item_t * symtab_item;
    bool is_const;
    size_t num_item;  // number of items (if existing)

    intmed_arg(std::string symbol, var_symbol_item_t * symtab_item = NULL, bool is_const = true, size_t num_item = 0) {
        this -> symbol = symbol;
        this -> symtab_item = symtab_item;
        this -> is_const = is_const;
        this -> num_item = num_item;
    }
} intmed_arg_t;

typedef struct intmed_code
{
    intmed_op_t op;
    intmed_arg_t result;
    val_type_t val_type;

    intmed_arg_t arg1;
    intmed_arg_t arg2;

} intmed_code_t;

typedef struct temp_info {
    size_t num_items;
    bool is_array;
    bool is_const;
    val_type_t dtype;
    var_symbol_item_t * symtab_item;

    temp_info(val_type_t dtype, size_t num_items = 0, bool is_array = false, bool is_const = false, var_symbol_item_t * symtab_item = NULL) {
        this -> dtype = dtype;
        this -> num_items = num_items;
        this -> is_array = is_array;
        this -> is_const = is_const;
        this -> symtab_item = symtab_item;
    }
} temp_info_t;

class IntermediateRepr : public CACTBaseListener
{
private:
    std::vector <intmed_code_t> intmed_array;

    // size_t num_temp = 0;
    std::map <std::string, temp_info_t *> temp_array;
    int scope_id;

public:
    std::map <intmed_op_t, const char *> op_to_string{
        {LD, "LD"},
        {ST, "ST"},
        {ADD, "ADD"},
        {ADD_V, "ADD_V"},
        {SUB, "SUB_V"},
        {NEG, "NEG_V"},
        {NOT, "NOT"},
        {MUL, "MUL"},
        {MUL_V, "MUL_V"},
        {DIV, "DIV"},
        {DIV_V, "DIV_V"},
        {MOD, "MOD"},
        {MOD_V, "MOD_V"},
        {AND, "AND"},
        {OR, "OR"},
        {CALL, "CALL"},
        {RETURN, "RETURN"},
        {PARAM, "PARAM"},
        {D_ALLOC, "D_ALLOC"},
        {G_ALLOC, "G_ALLOC"},
        {BEQ, "BEQ"},
        {BNE, "BNE"},
        {BLT, "BLT"},
        {BGT, "BGT"},
        {BLE, "BLE"},
        {BGE, "BGE"},
        {J, "J"},
    };

    typedef struct label
    {
        std::string name;
        int before_which_code;

        // Overload for compare operator to guarantee the order of labels
        // Order by `index`, but can be indexed by `before_which_code`
        bool operator<(label const &l) const
        {
            std::string this_name = this -> name;
            std::string name = l.name;
            size_t this_index = std::stoul(this_name.substr(1, this_name.length() - 1));
            size_t index = std::stoul(name.substr(1, name.length() - 1));
            return this_index < index;
        }
    } label_t;
    std::string current_func_end;

private:
    // First component: before which code
    std::map <int, label_t> label_array;
    size_t num_label = 0;
    std::map <scope_node_t * , int> encode_scope;

public:
    IntermediateRepr() {};
    ~IntermediateRepr() {};

    std::string newTemp(val_type_t dtype, size_t num_items = 0, bool is_array = false, bool is_const = false, var_symbol_item_t * symtab_item = NULL) {
        // Use % to distinguish
        std::string temp_name = TEMP_SUFFIX + std::to_string(temp_array.size());
        auto new_info = new temp_info_t(dtype, num_items, is_array, is_const, symtab_item);
        temp_array[temp_name] = new_info;
        return temp_name;
    }
    temp_info_t * getTempInfo(std::string name) {
        return temp_array[name];
    }
    void encodeScope();
    void visitScope(scope_node_t * scope);
    void symtabRename();

    inline std::string RENAME_VAR(std::string name, scope_node_t * scope)
    {
        return name + std::to_string(encode_scope[scope]);
    }

    void appendIntmed(intmed_op_t op, intmed_arg_t result, val_type_t type, intmed_arg_t arg1, intmed_arg_t arg2) {
        intmed_array.push_back((intmed_code_t){op, result, type, arg1, arg2});
    }
    void appendIntmed(intmed_op_t op, std::string result, val_type_t type, std::string arg1, std::string arg2) {
        appendIntmed(op, intmed_arg_t(result), type, intmed_arg_t(arg1), intmed_arg_t(arg2));
    }
    void appendIntmed(intmed_op_t op, intmed_arg_t result, val_type_t type, intmed_arg_t arg1) {
        appendIntmed(op, result, type, arg1, intmed_arg_t(""));
    }
    void appendIntmed(intmed_op_t op, std::string result, val_type_t type, std::string arg1) {
        appendIntmed(op, result, type, arg1, "");
    }
    void appendIntmed(intmed_op_t op, intmed_arg_t result, val_type_t type) {
        appendIntmed(op, result, type, intmed_arg_t(""));
    }
    void appendIntmed(intmed_op_t op, std::string result, val_type_t type) {
        appendIntmed(op, intmed_arg_t(result), type);
    }
    void appendIntmed(intmed_op_t op, val_type_t type, intmed_arg_t arg1) {
        appendIntmed(op, intmed_arg_t(""), type, arg1);
    }
    void appendIntmed(intmed_op_t op, val_type_t type, std::string arg1) {
        appendIntmed(op, type, intmed_arg_t(arg1));
    }
    void appendIntmed(intmed_op_t op, val_type_t type) {
        appendIntmed(op, intmed_arg_t(""), type, intmed_arg_t(""), intmed_arg_t(""));
    }

    size_t getIntmedNum() {
        return intmed_array.size();
    }

    intmed_code_t & getACode(size_t index) {
        return intmed_array[index];
    }

    std::vector <intmed_code_t> & getAllCode() {
        return intmed_array;
    }

    scope_node_t *current_scope;

    std::string newLabel() {
        return LABEL_SUFFIX + std::to_string(num_label ++);
    }
    void attachLabel(std::string label, size_t inst_num) {
        label_array[inst_num] = (label_t) {label, inst_num};
    }
    std::map <int, label_t> & getAllLabel() {
        return label_array;
    }

    void printIR(int ir_index);
    void printAllIR();

    void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;
    void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;

    void enterConstDef_empty(CACTParser::ConstDef_emptyContext * /*ctx*/) override {}
    void exitConstDef_empty(CACTParser::ConstDef_emptyContext * /*ctx*/) override;

    void enterConstDef_init(CACTParser::ConstDef_initContext * /*ctx*/) override {}
    void exitConstDef_init(CACTParser::ConstDef_initContext * /*ctx*/) override;

    void enterConstExp_single(CACTParser::ConstExp_singleContext * /*ctx*/) override {}
    void exitConstExp_single(CACTParser::ConstExp_singleContext * /*ctx*/) override;

    void enterConstExp_array(CACTParser::ConstExp_arrayContext * /*ctx*/) override {}
    void exitConstExp_array(CACTParser::ConstExp_arrayContext * /*ctx*/) override;

    void enterBType(CACTParser::BTypeContext * /*ctx*/) override;
    void exitBType(CACTParser::BTypeContext * /*ctx*/) override {}

    void enterVarDef_empty(CACTParser::VarDef_emptyContext * /*ctx*/) override { }
    void exitVarDef_empty(CACTParser::VarDef_emptyContext * /*ctx*/) override;

    void enterVarDef_init(CACTParser::VarDef_initContext * /*ctx*/) override { }
    void exitVarDef_init(CACTParser::VarDef_initContext * /*ctx*/) override;

    void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override {}
    void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;

    void enterFuncHeader(CACTParser::FuncHeaderContext * /*ctx*/) override;
    void exitFuncHeader(CACTParser::FuncHeaderContext * /*ctx*/) override {}

    void enterBlock(CACTParser::BlockContext * /*ctx*/) override;
    void exitBlock(CACTParser::BlockContext * /*ctx*/) override;

    void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override {}
    void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override {}

    void enterStmt_assign(CACTParser::Stmt_assignContext * /*ctx*/) override {}
    void exitStmt_assign(CACTParser::Stmt_assignContext * /*ctx*/) override;

    void enterStmt_exp(CACTParser::Stmt_expContext * /*ctx*/) override {}
    void exitStmt_exp(CACTParser::Stmt_expContext * /*ctx*/) override {}

    void enterStmt_block(CACTParser::Stmt_blockContext * /*ctx*/) override {}
    void exitStmt_block(CACTParser::Stmt_blockContext * /*ctx*/) override {}

    void enterLab(CACTParser::LabContext * /*ctx*/) override;
    void exitLab(CACTParser::LabContext * /*ctx*/) override { }

    void enterGo(CACTParser::GoContext * /*ctx*/) override;
    void exitGo(CACTParser::GoContext * /*ctx*/) override { }

    void enterStmt_if(CACTParser::Stmt_ifContext * /*ctx*/) override;
    void exitStmt_if(CACTParser::Stmt_ifContext * /*ctx*/) override;

    void enterStmt_while(CACTParser::Stmt_whileContext * /*ctx*/) override;
    void exitStmt_while(CACTParser::Stmt_whileContext * /*ctx*/) override;

    void enterStmt_break(CACTParser::Stmt_breakContext * /*ctx*/) override;
    void exitStmt_break(CACTParser::Stmt_breakContext * /*ctx*/) override {}

    void enterStmt_continue(CACTParser::Stmt_continueContext * /*ctx*/) override;
    void exitStmt_continue(CACTParser::Stmt_continueContext * /*ctx*/) override {}

    void enterStmt_return(CACTParser::Stmt_returnContext * /*ctx*/) override {}
    void exitStmt_return(CACTParser::Stmt_returnContext * /*ctx*/) override;

    void enterPrimaryExp_exp(CACTParser::PrimaryExp_expContext * /*ctx*/) override {}
    void exitPrimaryExp_exp(CACTParser::PrimaryExp_expContext * /*ctx*/) override;

    void enterPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * /*ctx*/) override;
    void exitPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * /*ctx*/) override;

    void enterPrimaryExp_num(CACTParser::PrimaryExp_numContext * /*ctx*/) override {}
    void exitPrimaryExp_num(CACTParser::PrimaryExp_numContext * /*ctx*/) override;

    void enterUnaryExp_primary(CACTParser::UnaryExp_primaryContext * /*ctx*/) override {}
    void exitUnaryExp_primary(CACTParser::UnaryExp_primaryContext * /*ctx*/) override;

    void enterUnaryExp_call(CACTParser::UnaryExp_callContext * /*ctx*/) override {}
    void exitUnaryExp_call(CACTParser::UnaryExp_callContext * /*ctx*/) override;

    void enterUnaryExp_uop(CACTParser::UnaryExp_uopContext * /*ctx*/) override {}
    void exitUnaryExp_uop(CACTParser::UnaryExp_uopContext * /*ctx*/) override;

    void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override {}
    void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override {}

    void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override {}
    void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override;

    void enterConstExp_num(CACTParser::ConstExp_numContext * /*ctx*/) override {}
    void exitConstExp_num(CACTParser::ConstExp_numContext * /*ctx*/) override;

    void enterConstExp_bool(CACTParser::ConstExp_boolContext * /*ctx*/) override {}
    void exitConstExp_bool(CACTParser::ConstExp_boolContext * /*ctx*/) override;

    void enterNumber_int(CACTParser::Number_intContext * /*ctx*/) override {}
    void exitNumber_int(CACTParser::Number_intContext * /*ctx*/) override;

    void enterNumber_double(CACTParser::Number_doubleContext * /*ctx*/) override {}
    void exitNumber_double(CACTParser::Number_doubleContext * /*ctx*/) override;

    void enterNumber_float(CACTParser::Number_floatContext * /*ctx*/) override {}
    void exitNumber_float(CACTParser::Number_floatContext * /*ctx*/) override;

    void enterCond(CACTParser::CondContext * /*ctx*/) override;
    void exitCond(CACTParser::CondContext * /*ctx*/) override {}

    void enterExp_add(CACTParser::Exp_addContext * /*ctx*/) override {}
    void exitExp_add(CACTParser::Exp_addContext * /*ctx*/) override;

    void enterExp_bool(CACTParser::Exp_boolContext * /*ctx*/) override {}
    void exitExp_bool(CACTParser::Exp_boolContext * /*ctx*/) override;

    void enterMulExp_unary(CACTParser::MulExp_unaryContext * /*ctx*/) override {}
    void exitMulExp_unary(CACTParser::MulExp_unaryContext * /*ctx*/) override;

    void enterMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * /*ctx*/) override {}
    void exitMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * /*ctx*/) override;

    void enterAddExp_mul(CACTParser::AddExp_mulContext * /*ctx*/) override {}
    void exitAddExp_mul(CACTParser::AddExp_mulContext * /*ctx*/) override;

    void enterAddExp_add_mul(CACTParser::AddExp_add_mulContext * /*ctx*/) override {}
    void exitAddExp_add_mul(CACTParser::AddExp_add_mulContext * /*ctx*/) override;

    void enterRelExp_bool(CACTParser::RelExp_boolContext * /*ctx*/) override {}
    void exitRelExp_bool(CACTParser::RelExp_boolContext * /*ctx*/) override;

    void enterRelExp_rel_add(CACTParser::RelExp_rel_addContext * /*ctx*/) override {}
    void exitRelExp_rel_add(CACTParser::RelExp_rel_addContext * /*ctx*/) override;

    void enterRelExp_add(CACTParser::RelExp_addContext * /*ctx*/) override {}
    void exitRelExp_add(CACTParser::RelExp_addContext * /*ctx*/) override;

    void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override;
    void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override;

    void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;
    void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;

    void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;
    void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;
    template <typename T_ctx>
    void exitConstAndVarDef(T_ctx &ctx, std::string value_list = "");

    template <typename T_ctx>
    void exitConstAndVarDefInit(T_ctx &ctx);

    void blockPartition();
};
