
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CACTListener.h"


/**
 * This class provides an empty implementation of CACTListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CACTBaseListener : public CACTListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef_empty(CACTParser::ConstDef_emptyContext * /*ctx*/) override { }
  virtual void exitConstDef_empty(CACTParser::ConstDef_emptyContext * /*ctx*/) override { }

  virtual void enterConstDef_init(CACTParser::ConstDef_initContext * /*ctx*/) override { }
  virtual void exitConstDef_init(CACTParser::ConstDef_initContext * /*ctx*/) override { }

  virtual void enterConstExp_single(CACTParser::ConstExp_singleContext * /*ctx*/) override { }
  virtual void exitConstExp_single(CACTParser::ConstExp_singleContext * /*ctx*/) override { }

  virtual void enterConstExp_array(CACTParser::ConstExp_arrayContext * /*ctx*/) override { }
  virtual void exitConstExp_array(CACTParser::ConstExp_arrayContext * /*ctx*/) override { }

  virtual void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef_empty(CACTParser::VarDef_emptyContext * /*ctx*/) override { }
  virtual void exitVarDef_empty(CACTParser::VarDef_emptyContext * /*ctx*/) override { }

  virtual void enterVarDef_init(CACTParser::VarDef_initContext * /*ctx*/) override { }
  virtual void exitVarDef_init(CACTParser::VarDef_initContext * /*ctx*/) override { }

  virtual void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncHeader(CACTParser::FuncHeaderContext * /*ctx*/) override { }
  virtual void exitFuncHeader(CACTParser::FuncHeaderContext * /*ctx*/) override { }

  virtual void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParam_single(CACTParser::FuncFParam_singleContext * /*ctx*/) override { }
  virtual void exitFuncFParam_single(CACTParser::FuncFParam_singleContext * /*ctx*/) override { }

  virtual void enterFuncFParam_array(CACTParser::FuncFParam_arrayContext * /*ctx*/) override { }
  virtual void exitFuncFParam_array(CACTParser::FuncFParam_arrayContext * /*ctx*/) override { }

  virtual void enterBlock(CACTParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CACTParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStmt_assign(CACTParser::Stmt_assignContext * /*ctx*/) override { }
  virtual void exitStmt_assign(CACTParser::Stmt_assignContext * /*ctx*/) override { }

  virtual void enterStmt_exp(CACTParser::Stmt_expContext * /*ctx*/) override { }
  virtual void exitStmt_exp(CACTParser::Stmt_expContext * /*ctx*/) override { }

  virtual void enterStmt_block(CACTParser::Stmt_blockContext * /*ctx*/) override { }
  virtual void exitStmt_block(CACTParser::Stmt_blockContext * /*ctx*/) override { }

  virtual void enterStmt_if(CACTParser::Stmt_ifContext * /*ctx*/) override { }
  virtual void exitStmt_if(CACTParser::Stmt_ifContext * /*ctx*/) override { }

  virtual void enterStmt_while(CACTParser::Stmt_whileContext * /*ctx*/) override { }
  virtual void exitStmt_while(CACTParser::Stmt_whileContext * /*ctx*/) override { }

  virtual void enterStmt_break(CACTParser::Stmt_breakContext * /*ctx*/) override { }
  virtual void exitStmt_break(CACTParser::Stmt_breakContext * /*ctx*/) override { }

  virtual void enterStmt_continue(CACTParser::Stmt_continueContext * /*ctx*/) override { }
  virtual void exitStmt_continue(CACTParser::Stmt_continueContext * /*ctx*/) override { }

  virtual void enterStmt_return(CACTParser::Stmt_returnContext * /*ctx*/) override { }
  virtual void exitStmt_return(CACTParser::Stmt_returnContext * /*ctx*/) override { }

  virtual void enterLab(CACTParser::LabContext * /*ctx*/) override { }
  virtual void exitLab(CACTParser::LabContext * /*ctx*/) override { }

  virtual void enterGo(CACTParser::GoContext * /*ctx*/) override { }
  virtual void exitGo(CACTParser::GoContext * /*ctx*/) override { }

  virtual void enterExp_add(CACTParser::Exp_addContext * /*ctx*/) override { }
  virtual void exitExp_add(CACTParser::Exp_addContext * /*ctx*/) override { }

  virtual void enterExp_bool(CACTParser::Exp_boolContext * /*ctx*/) override { }
  virtual void exitExp_bool(CACTParser::Exp_boolContext * /*ctx*/) override { }

  virtual void enterCond(CACTParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(CACTParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(CACTParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(CACTParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExp_exp(CACTParser::PrimaryExp_expContext * /*ctx*/) override { }
  virtual void exitPrimaryExp_exp(CACTParser::PrimaryExp_expContext * /*ctx*/) override { }

  virtual void enterPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * /*ctx*/) override { }
  virtual void exitPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * /*ctx*/) override { }

  virtual void enterPrimaryExp_num(CACTParser::PrimaryExp_numContext * /*ctx*/) override { }
  virtual void exitPrimaryExp_num(CACTParser::PrimaryExp_numContext * /*ctx*/) override { }

  virtual void enterUnaryExp_primary(CACTParser::UnaryExp_primaryContext * /*ctx*/) override { }
  virtual void exitUnaryExp_primary(CACTParser::UnaryExp_primaryContext * /*ctx*/) override { }

  virtual void enterUnaryExp_call(CACTParser::UnaryExp_callContext * /*ctx*/) override { }
  virtual void exitUnaryExp_call(CACTParser::UnaryExp_callContext * /*ctx*/) override { }

  virtual void enterUnaryExp_uop(CACTParser::UnaryExp_uopContext * /*ctx*/) override { }
  virtual void exitUnaryExp_uop(CACTParser::UnaryExp_uopContext * /*ctx*/) override { }

  virtual void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExp_unary(CACTParser::MulExp_unaryContext * /*ctx*/) override { }
  virtual void exitMulExp_unary(CACTParser::MulExp_unaryContext * /*ctx*/) override { }

  virtual void enterMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * /*ctx*/) override { }
  virtual void exitMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * /*ctx*/) override { }

  virtual void enterMulOp(CACTParser::MulOpContext * /*ctx*/) override { }
  virtual void exitMulOp(CACTParser::MulOpContext * /*ctx*/) override { }

  virtual void enterAddExp_mul(CACTParser::AddExp_mulContext * /*ctx*/) override { }
  virtual void exitAddExp_mul(CACTParser::AddExp_mulContext * /*ctx*/) override { }

  virtual void enterAddExp_add_mul(CACTParser::AddExp_add_mulContext * /*ctx*/) override { }
  virtual void exitAddExp_add_mul(CACTParser::AddExp_add_mulContext * /*ctx*/) override { }

  virtual void enterAddOp(CACTParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(CACTParser::AddOpContext * /*ctx*/) override { }

  virtual void enterRelExp_bool(CACTParser::RelExp_boolContext * /*ctx*/) override { }
  virtual void exitRelExp_bool(CACTParser::RelExp_boolContext * /*ctx*/) override { }

  virtual void enterRelExp_rel_add(CACTParser::RelExp_rel_addContext * /*ctx*/) override { }
  virtual void exitRelExp_rel_add(CACTParser::RelExp_rel_addContext * /*ctx*/) override { }

  virtual void enterRelExp_add(CACTParser::RelExp_addContext * /*ctx*/) override { }
  virtual void exitRelExp_add(CACTParser::RelExp_addContext * /*ctx*/) override { }

  virtual void enterRelOp(CACTParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(CACTParser::RelOpContext * /*ctx*/) override { }

  virtual void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override { }
  virtual void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override { }

  virtual void enterEqOp(CACTParser::EqOpContext * /*ctx*/) override { }
  virtual void exitEqOp(CACTParser::EqOpContext * /*ctx*/) override { }

  virtual void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterConstExp_num(CACTParser::ConstExp_numContext * /*ctx*/) override { }
  virtual void exitConstExp_num(CACTParser::ConstExp_numContext * /*ctx*/) override { }

  virtual void enterConstExp_bool(CACTParser::ConstExp_boolContext * /*ctx*/) override { }
  virtual void exitConstExp_bool(CACTParser::ConstExp_boolContext * /*ctx*/) override { }

  virtual void enterNumber_int(CACTParser::Number_intContext * /*ctx*/) override { }
  virtual void exitNumber_int(CACTParser::Number_intContext * /*ctx*/) override { }

  virtual void enterNumber_double(CACTParser::Number_doubleContext * /*ctx*/) override { }
  virtual void exitNumber_double(CACTParser::Number_doubleContext * /*ctx*/) override { }

  virtual void enterNumber_float(CACTParser::Number_floatContext * /*ctx*/) override { }
  virtual void exitNumber_float(CACTParser::Number_floatContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

