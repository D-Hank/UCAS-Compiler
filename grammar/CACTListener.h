
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CACTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CACTParser.
 */
class  CACTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(CACTParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(CACTParser::DeclContext *ctx) = 0;
  virtual void exitDecl(CACTParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(CACTParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(CACTParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(CACTParser::BTypeContext *ctx) = 0;
  virtual void exitBType(CACTParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef_empty(CACTParser::ConstDef_emptyContext *ctx) = 0;
  virtual void exitConstDef_empty(CACTParser::ConstDef_emptyContext *ctx) = 0;

  virtual void enterConstDef_init(CACTParser::ConstDef_initContext *ctx) = 0;
  virtual void exitConstDef_init(CACTParser::ConstDef_initContext *ctx) = 0;

  virtual void enterConstExp_single(CACTParser::ConstExp_singleContext *ctx) = 0;
  virtual void exitConstExp_single(CACTParser::ConstExp_singleContext *ctx) = 0;

  virtual void enterConstExp_array(CACTParser::ConstExp_arrayContext *ctx) = 0;
  virtual void exitConstExp_array(CACTParser::ConstExp_arrayContext *ctx) = 0;

  virtual void enterVarDecl(CACTParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CACTParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef_empty(CACTParser::VarDef_emptyContext *ctx) = 0;
  virtual void exitVarDef_empty(CACTParser::VarDef_emptyContext *ctx) = 0;

  virtual void enterVarDef_init(CACTParser::VarDef_initContext *ctx) = 0;
  virtual void exitVarDef_init(CACTParser::VarDef_initContext *ctx) = 0;

  virtual void enterFuncDef(CACTParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(CACTParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncHeader(CACTParser::FuncHeaderContext *ctx) = 0;
  virtual void exitFuncHeader(CACTParser::FuncHeaderContext *ctx) = 0;

  virtual void enterFuncType(CACTParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(CACTParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParam_single(CACTParser::FuncFParam_singleContext *ctx) = 0;
  virtual void exitFuncFParam_single(CACTParser::FuncFParam_singleContext *ctx) = 0;

  virtual void enterFuncFParam_array(CACTParser::FuncFParam_arrayContext *ctx) = 0;
  virtual void exitFuncFParam_array(CACTParser::FuncFParam_arrayContext *ctx) = 0;

  virtual void enterBlock(CACTParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CACTParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(CACTParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(CACTParser::BlockItemContext *ctx) = 0;

  virtual void enterStmt_assign(CACTParser::Stmt_assignContext *ctx) = 0;
  virtual void exitStmt_assign(CACTParser::Stmt_assignContext *ctx) = 0;

  virtual void enterStmt_exp(CACTParser::Stmt_expContext *ctx) = 0;
  virtual void exitStmt_exp(CACTParser::Stmt_expContext *ctx) = 0;

  virtual void enterStmt_block(CACTParser::Stmt_blockContext *ctx) = 0;
  virtual void exitStmt_block(CACTParser::Stmt_blockContext *ctx) = 0;

  virtual void enterStmt_if(CACTParser::Stmt_ifContext *ctx) = 0;
  virtual void exitStmt_if(CACTParser::Stmt_ifContext *ctx) = 0;

  virtual void enterStmt_while(CACTParser::Stmt_whileContext *ctx) = 0;
  virtual void exitStmt_while(CACTParser::Stmt_whileContext *ctx) = 0;

  virtual void enterStmt_break(CACTParser::Stmt_breakContext *ctx) = 0;
  virtual void exitStmt_break(CACTParser::Stmt_breakContext *ctx) = 0;

  virtual void enterStmt_continue(CACTParser::Stmt_continueContext *ctx) = 0;
  virtual void exitStmt_continue(CACTParser::Stmt_continueContext *ctx) = 0;

  virtual void enterStmt_return(CACTParser::Stmt_returnContext *ctx) = 0;
  virtual void exitStmt_return(CACTParser::Stmt_returnContext *ctx) = 0;

  virtual void enterLab(CACTParser::LabContext *ctx) = 0;
  virtual void exitLab(CACTParser::LabContext *ctx) = 0;

  virtual void enterGo(CACTParser::GoContext *ctx) = 0;
  virtual void exitGo(CACTParser::GoContext *ctx) = 0;

  virtual void enterExp_add(CACTParser::Exp_addContext *ctx) = 0;
  virtual void exitExp_add(CACTParser::Exp_addContext *ctx) = 0;

  virtual void enterExp_bool(CACTParser::Exp_boolContext *ctx) = 0;
  virtual void exitExp_bool(CACTParser::Exp_boolContext *ctx) = 0;

  virtual void enterCond(CACTParser::CondContext *ctx) = 0;
  virtual void exitCond(CACTParser::CondContext *ctx) = 0;

  virtual void enterLVal(CACTParser::LValContext *ctx) = 0;
  virtual void exitLVal(CACTParser::LValContext *ctx) = 0;

  virtual void enterPrimaryExp_exp(CACTParser::PrimaryExp_expContext *ctx) = 0;
  virtual void exitPrimaryExp_exp(CACTParser::PrimaryExp_expContext *ctx) = 0;

  virtual void enterPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext *ctx) = 0;
  virtual void exitPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext *ctx) = 0;

  virtual void enterPrimaryExp_num(CACTParser::PrimaryExp_numContext *ctx) = 0;
  virtual void exitPrimaryExp_num(CACTParser::PrimaryExp_numContext *ctx) = 0;

  virtual void enterUnaryExp_primary(CACTParser::UnaryExp_primaryContext *ctx) = 0;
  virtual void exitUnaryExp_primary(CACTParser::UnaryExp_primaryContext *ctx) = 0;

  virtual void enterUnaryExp_call(CACTParser::UnaryExp_callContext *ctx) = 0;
  virtual void exitUnaryExp_call(CACTParser::UnaryExp_callContext *ctx) = 0;

  virtual void enterUnaryExp_uop(CACTParser::UnaryExp_uopContext *ctx) = 0;
  virtual void exitUnaryExp_uop(CACTParser::UnaryExp_uopContext *ctx) = 0;

  virtual void enterUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;

  virtual void enterMulExp_unary(CACTParser::MulExp_unaryContext *ctx) = 0;
  virtual void exitMulExp_unary(CACTParser::MulExp_unaryContext *ctx) = 0;

  virtual void enterMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext *ctx) = 0;
  virtual void exitMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext *ctx) = 0;

  virtual void enterMulOp(CACTParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(CACTParser::MulOpContext *ctx) = 0;

  virtual void enterAddExp_mul(CACTParser::AddExp_mulContext *ctx) = 0;
  virtual void exitAddExp_mul(CACTParser::AddExp_mulContext *ctx) = 0;

  virtual void enterAddExp_add_mul(CACTParser::AddExp_add_mulContext *ctx) = 0;
  virtual void exitAddExp_add_mul(CACTParser::AddExp_add_mulContext *ctx) = 0;

  virtual void enterAddOp(CACTParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(CACTParser::AddOpContext *ctx) = 0;

  virtual void enterRelExp_bool(CACTParser::RelExp_boolContext *ctx) = 0;
  virtual void exitRelExp_bool(CACTParser::RelExp_boolContext *ctx) = 0;

  virtual void enterRelExp_rel_add(CACTParser::RelExp_rel_addContext *ctx) = 0;
  virtual void exitRelExp_rel_add(CACTParser::RelExp_rel_addContext *ctx) = 0;

  virtual void enterRelExp_add(CACTParser::RelExp_addContext *ctx) = 0;
  virtual void exitRelExp_add(CACTParser::RelExp_addContext *ctx) = 0;

  virtual void enterRelOp(CACTParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(CACTParser::RelOpContext *ctx) = 0;

  virtual void enterEqExp(CACTParser::EqExpContext *ctx) = 0;
  virtual void exitEqExp(CACTParser::EqExpContext *ctx) = 0;

  virtual void enterEqOp(CACTParser::EqOpContext *ctx) = 0;
  virtual void exitEqOp(CACTParser::EqOpContext *ctx) = 0;

  virtual void enterLAndExp(CACTParser::LAndExpContext *ctx) = 0;
  virtual void exitLAndExp(CACTParser::LAndExpContext *ctx) = 0;

  virtual void enterLOrExp(CACTParser::LOrExpContext *ctx) = 0;
  virtual void exitLOrExp(CACTParser::LOrExpContext *ctx) = 0;

  virtual void enterConstExp_num(CACTParser::ConstExp_numContext *ctx) = 0;
  virtual void exitConstExp_num(CACTParser::ConstExp_numContext *ctx) = 0;

  virtual void enterConstExp_bool(CACTParser::ConstExp_boolContext *ctx) = 0;
  virtual void exitConstExp_bool(CACTParser::ConstExp_boolContext *ctx) = 0;

  virtual void enterNumber_int(CACTParser::Number_intContext *ctx) = 0;
  virtual void exitNumber_int(CACTParser::Number_intContext *ctx) = 0;

  virtual void enterNumber_double(CACTParser::Number_doubleContext *ctx) = 0;
  virtual void exitNumber_double(CACTParser::Number_doubleContext *ctx) = 0;

  virtual void enterNumber_float(CACTParser::Number_floatContext *ctx) = 0;
  virtual void exitNumber_float(CACTParser::Number_floatContext *ctx) = 0;


};

