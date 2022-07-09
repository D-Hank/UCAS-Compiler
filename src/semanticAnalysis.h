#pragma once

#include "../grammar/CACTBaseListener.h"

#include <vector>
#include <map>
#include <unordered_map>

#include "symbolTable.h"

extern SymbolTable symbol_table;

class SemanticAnalysis : public CACTBaseListener
{
private:
    /* data */

public:
    SemanticAnalysis(/* args */){}
    ~SemanticAnalysis(){}

    // Global scope
    scope_node_t *current_scope;

    void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;
    void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;

    void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
    void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

    void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }
    void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;

    void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
    void exitBType(CACTParser::BTypeContext * /*ctx*/) override;

    void enterConstDef_empty(CACTParser::ConstDef_emptyContext * /*ctx*/) override { }
    void exitConstDef_empty(CACTParser::ConstDef_emptyContext * /*ctx*/) override;

    void enterConstDef_init(CACTParser::ConstDef_initContext * /*ctx*/) override { }
    void exitConstDef_init(CACTParser::ConstDef_initContext * /*ctx*/) override;

    void enterConstExp_single(CACTParser::ConstExp_singleContext * /*ctx*/) override { }
    void exitConstExp_single(CACTParser::ConstExp_singleContext * /*ctx*/) override;

    void enterConstExp_array(CACTParser::ConstExp_arrayContext * /*ctx*/) override { }
    void exitConstExp_array(CACTParser::ConstExp_arrayContext * /*ctx*/) override;

    void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }
    void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;

    void enterVarDef_empty(CACTParser::VarDef_emptyContext * /*ctx*/) override { }
    void exitVarDef_empty(CACTParser::VarDef_emptyContext * /*ctx*/) override;

    void enterVarDef_init(CACTParser::VarDef_initContext * /*ctx*/) override { }
    void exitVarDef_init(CACTParser::VarDef_initContext * /*ctx*/) override;

    void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;
    void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;

    void enterFuncHeader(CACTParser::FuncHeaderContext * /*ctx*/) override { }
    void exitFuncHeader(CACTParser::FuncHeaderContext * /*ctx*/) override;

    void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }
    void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override;

    void enterFuncFParam_single(CACTParser::FuncFParam_singleContext * /*ctx*/) override { }
    void exitFuncFParam_single(CACTParser::FuncFParam_singleContext * /*ctx*/) override;

    void enterFuncFParam_array(CACTParser::FuncFParam_arrayContext * /*ctx*/) override { }
    void exitFuncFParam_array(CACTParser::FuncFParam_arrayContext * /*ctx*/) override;

    void enterBlock(CACTParser::BlockContext * /*ctx*/) override;
    void exitBlock(CACTParser::BlockContext * /*ctx*/) override;

    void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override;
    void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override;

    void enterStmt_assign(CACTParser::Stmt_assignContext * /*ctx*/) override { }
    void exitStmt_assign(CACTParser::Stmt_assignContext * /*ctx*/) override;

    void enterStmt_exp(CACTParser::Stmt_expContext * /*ctx*/) override { }
    void exitStmt_exp(CACTParser::Stmt_expContext * /*ctx*/) override;

    void enterStmt_block(CACTParser::Stmt_blockContext * /*ctx*/) override;
    void exitStmt_block(CACTParser::Stmt_blockContext * /*ctx*/) override;

    void enterStmt_if(CACTParser::Stmt_ifContext * /*ctx*/) override;
    void exitStmt_if(CACTParser::Stmt_ifContext * /*ctx*/) override;

    void enterStmt_while(CACTParser::Stmt_whileContext * /*ctx*/) override;
    void exitStmt_while(CACTParser::Stmt_whileContext * /*ctx*/) override;

    void enterStmt_break(CACTParser::Stmt_breakContext * /*ctx*/) override;
    void exitStmt_break(CACTParser::Stmt_breakContext * /*ctx*/) override { }

    void enterStmt_continue(CACTParser::Stmt_continueContext * /*ctx*/) override;
    void exitStmt_continue(CACTParser::Stmt_continueContext * /*ctx*/) override { }

    void enterStmt_return(CACTParser::Stmt_returnContext * /*ctx*/) override;
    void exitStmt_return(CACTParser::Stmt_returnContext * /*ctx*/) override;

    void enterExp_add(CACTParser::Exp_addContext * /*ctx*/) override { }
    void exitExp_add(CACTParser::Exp_addContext * /*ctx*/) override;

    void enterExp_bool(CACTParser::Exp_boolContext * /*ctx*/) override { }
    void exitExp_bool(CACTParser::Exp_boolContext * /*ctx*/) override;

    void enterCond(CACTParser::CondContext * /*ctx*/) override { }
    void exitCond(CACTParser::CondContext * /*ctx*/) override;

    void enterLVal(CACTParser::LValContext * /*ctx*/) override { }
    void exitLVal(CACTParser::LValContext * /*ctx*/) override;

    void enterPrimaryExp_exp(CACTParser::PrimaryExp_expContext * /*ctx*/) override { }
    void exitPrimaryExp_exp(CACTParser::PrimaryExp_expContext * /*ctx*/) override;

    void enterPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * /*ctx*/) override { }
    void exitPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * /*ctx*/) override;

    void enterPrimaryExp_num(CACTParser::PrimaryExp_numContext * /*ctx*/) override { }
    void exitPrimaryExp_num(CACTParser::PrimaryExp_numContext * /*ctx*/) override;

    void enterUnaryExp_primary(CACTParser::UnaryExp_primaryContext * /*ctx*/) override { }
    void exitUnaryExp_primary(CACTParser::UnaryExp_primaryContext * /*ctx*/) override;

    void enterUnaryExp_call(CACTParser::UnaryExp_callContext * /*ctx*/) override { }
    void exitUnaryExp_call(CACTParser::UnaryExp_callContext * /*ctx*/) override;

    void enterUnaryExp_uop(CACTParser::UnaryExp_uopContext * /*ctx*/) override { }
    void exitUnaryExp_uop(CACTParser::UnaryExp_uopContext * /*ctx*/) override;

    void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
    void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }

    void enterMulExp_unary(CACTParser::MulExp_unaryContext * /*ctx*/) override { }
    void exitMulExp_unary(CACTParser::MulExp_unaryContext * /*ctx*/) override;

    void enterMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * /*ctx*/) override { }
    void exitMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * /*ctx*/) override;

    void enterAddExp_mul(CACTParser::AddExp_mulContext * /*ctx*/) override { }
    void exitAddExp_mul(CACTParser::AddExp_mulContext * /*ctx*/) override;

    void enterAddExp_add_mul(CACTParser::AddExp_add_mulContext * /*ctx*/) override { }
    void exitAddExp_add_mul(CACTParser::AddExp_add_mulContext * /*ctx*/) override;

    void enterRelExp_bool(CACTParser::RelExp_boolContext * /*ctx*/) override { }
    void exitRelExp_bool(CACTParser::RelExp_boolContext * /*ctx*/) override;

    void enterRelExp_rel_add(CACTParser::RelExp_rel_addContext * /*ctx*/) override { }
    void exitRelExp_rel_add(CACTParser::RelExp_rel_addContext * /*ctx*/) override;

    void enterRelExp_add(CACTParser::RelExp_addContext * /*ctx*/) override { }
    void exitRelExp_add(CACTParser::RelExp_addContext * /*ctx*/) override;

    void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override { }
    void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override;

    void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }
    void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;

    void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }
    void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;

    void enterConstExp_num(CACTParser::ConstExp_numContext * /*ctx*/) override { }
    void exitConstExp_num(CACTParser::ConstExp_numContext * /*ctx*/) override;

    void enterConstExp_bool(CACTParser::ConstExp_boolContext * /*ctx*/) override { }
    void exitConstExp_bool(CACTParser::ConstExp_boolContext * /*ctx*/) override;

    void enterNumber_int(CACTParser::Number_intContext * /*ctx*/) override { }
    void exitNumber_int(CACTParser::Number_intContext * /*ctx*/) override;

    void enterNumber_double(CACTParser::Number_doubleContext * /*ctx*/) override { }
    void exitNumber_double(CACTParser::Number_doubleContext * /*ctx*/) override;

    void enterNumber_float(CACTParser::Number_floatContext * /*ctx*/) override { }
    void exitNumber_float(CACTParser::Number_floatContext * /*ctx*/) override;


    void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
    void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;

    template <typename T_ctx>
    void exitConstAndVarDef(T_ctx &ctx, bool is_array_right_side = true, size_t num_items_right_side = 0, int type_right_side = (int)(void_type));

    template <typename T_ctx>
    void exitConstAndVarDefInit(T_ctx &ctx);

    void addFunc(std::string func_name, int argc, val_type_t arg_type, val_type_t ret_type, std::string arg_name = "a");

    void checkMainFunc();
    void addBuiltInFunc();
};
