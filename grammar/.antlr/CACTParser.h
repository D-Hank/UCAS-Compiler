
    #include <vector>
    #include <string>


// Generated from /home/ubuntu/cactcompiler/compiler/grammar/CACT.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  CACTParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, BoolConst = 36, Ident = 37, IntConst = 38, 
    FloatConst = 39, DoubleConst = 40, NewLine = 41, WhiteSpace = 42, BlockComment = 43, 
    LineComment = 44
  };

  enum {
    RuleCompUnit = 0, RuleDecl = 1, RuleConstDecl = 2, RuleBType = 3, RuleConstDef = 4, 
    RuleConstInitVal = 5, RuleVarDecl = 6, RuleVarDef = 7, RuleFuncDef = 8, 
    RuleFuncHeader = 9, RuleFuncType = 10, RuleFuncFParam = 11, RuleBlock = 12, 
    RuleBlockItem = 13, RuleStmt = 14, RuleLab = 15, RuleGo = 16, RuleExp = 17, 
    RuleCond = 18, RuleLVal = 19, RulePrimaryExp = 20, RuleUnaryExp = 21, 
    RuleUnaryOp = 22, RuleFuncRParams = 23, RuleMulExp = 24, RuleMulOp = 25, 
    RuleAddExp = 26, RuleAddOp = 27, RuleRelExp = 28, RuleRelOp = 29, RuleEqExp = 30, 
    RuleEqOp = 31, RuleLAndExp = 32, RuleLOrExp = 33, RuleConstExp = 34, 
    RuleNumber = 35
  };

  explicit CACTParser(antlr4::TokenStream *input);
  ~CACTParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class BTypeContext;
  class ConstDefContext;
  class ConstInitValContext;
  class VarDeclContext;
  class VarDefContext;
  class FuncDefContext;
  class FuncHeaderContext;
  class FuncTypeContext;
  class FuncFParamContext;
  class BlockContext;
  class BlockItemContext;
  class StmtContext;
  class LabContext;
  class GoContext;
  class ExpContext;
  class CondContext;
  class LValContext;
  class PrimaryExpContext;
  class UnaryExpContext;
  class UnaryOpContext;
  class FuncRParamsContext;
  class MulExpContext;
  class MulOpContext;
  class AddExpContext;
  class AddOpContext;
  class RelExpContext;
  class RelOpContext;
  class EqExpContext;
  class EqOpContext;
  class LAndExpContext;
  class LOrExpContext;
  class ConstExpContext;
  class NumberContext; 

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);

   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();

   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    int const_decl_val_type;
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);

   
  };

  ConstDeclContext* constDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    int btype_val_type;
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  BTypeContext* bType();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    std::string id_name;
    int def_val_type;
    bool is_array;
    size_t num_items;
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstDefContext() = default;
    void copyFrom(ConstDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstDef_initContext : public ConstDefContext {
  public:
    ConstDef_initContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstInitValContext *constInitVal();
    antlr4::tree::TerminalNode *IntConst();
  };

  class  ConstDef_emptyContext : public ConstDefContext {
  public:
    ConstDef_emptyContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
  };

  ConstDefContext* constDef();

  class  ConstInitValContext : public antlr4::ParserRuleContext {
  public:
    int init_val_type;
    size_t num_items;
    bool is_array;
    std::string value_list;
    ConstInitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstInitValContext() = default;
    void copyFrom(ConstInitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstExp_singleContext : public ConstInitValContext {
  public:
    ConstExp_singleContext(ConstInitValContext *ctx);

    ConstExpContext *constExp();
  };

  class  ConstExp_arrayContext : public ConstInitValContext {
  public:
    ConstExp_arrayContext(ConstInitValContext *ctx);

    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
  };

  ConstInitValContext* constInitVal();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    int var_decl_val_type;
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);

   
  };

  VarDeclContext* varDecl();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    std::string id_name;
    int def_val_type;
    bool is_array;
    size_t num_items;
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarDefContext() = default;
    void copyFrom(VarDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarDef_emptyContext : public VarDefContext {
  public:
    VarDef_emptyContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
  };

  class  VarDef_initContext : public VarDefContext {
  public:
    VarDef_initContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstInitValContext *constInitVal();
    antlr4::tree::TerminalNode *IntConst();
  };

  VarDefContext* varDef();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncHeaderContext *funcHeader();
    BlockContext *block();

   
  };

  FuncDefContext* funcDef();

  class  FuncHeaderContext : public antlr4::ParserRuleContext {
  public:
    std::string * name_to_fill;
    FuncHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *Ident();
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);

   
  };

  FuncHeaderContext* funcHeader();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    int func_type;
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  FuncTypeContext* funcType();

  class  FuncFParamContext : public antlr4::ParserRuleContext {
  public:
    std::string arg_name;
    int arg_type;
    bool is_array;
    FuncFParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FuncFParamContext() = default;
    void copyFrom(FuncFParamContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FuncFParam_singleContext : public FuncFParamContext {
  public:
    FuncFParam_singleContext(FuncFParamContext *ctx);

    BTypeContext *bType();
    antlr4::tree::TerminalNode *Ident();
  };

  class  FuncFParam_arrayContext : public FuncFParamContext {
  public:
    FuncFParam_arrayContext(FuncFParamContext *ctx);

    BTypeContext *bType();
    antlr4::tree::TerminalNode *Ident();
  };

  FuncFParamContext* funcFParam();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    bool allow_break = false;
    bool allow_continue = false;
    bool allow_return = false;
    bool actual_has_return = false;
    int actual_return_type;
    bool from_func = false;
    std::string * which_func = nullptr;
    int index_in_father;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);

   
  };

  BlockContext* block();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    bool allow_break = false;
    bool allow_continue = false;
    bool allow_return = false;
    bool actual_has_return = false;
    int actual_return_type;
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();

   
  };

  BlockItemContext* blockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    bool allow_break = false;
    bool allow_continue = false;
    bool allow_return = false;
    int stmt_type;
    int stmt_val_type;
    bool actual_has_return = false;
    int actual_return_type;
    bool else_flag = false;
    std::string while_begin;
    std::string while_end;
    std::string nextlist;
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Stmt_ifContext : public StmtContext {
  public:
    Stmt_ifContext(StmtContext *ctx);

    CondContext *cond();
    std::vector<LabContext *> lab();
    LabContext* lab(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    GoContext *go();
  };

  class  Stmt_blockContext : public StmtContext {
  public:
    Stmt_blockContext(StmtContext *ctx);

    BlockContext *block();
  };

  class  Stmt_breakContext : public StmtContext {
  public:
    Stmt_breakContext(StmtContext *ctx);

  };

  class  Stmt_continueContext : public StmtContext {
  public:
    Stmt_continueContext(StmtContext *ctx);

  };

  class  Stmt_whileContext : public StmtContext {
  public:
    Stmt_whileContext(StmtContext *ctx);

    std::vector<LabContext *> lab();
    LabContext* lab(size_t i);
    CondContext *cond();
    StmtContext *stmt();
    GoContext *go();
  };

  class  Stmt_assignContext : public StmtContext {
  public:
    Stmt_assignContext(StmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();
  };

  class  Stmt_returnContext : public StmtContext {
  public:
    Stmt_returnContext(StmtContext *ctx);

    ExpContext *exp();
  };

  class  Stmt_expContext : public StmtContext {
  public:
    Stmt_expContext(StmtContext *ctx);

    ExpContext *exp();
  };

  StmtContext* stmt();

  class  LabContext : public antlr4::ParserRuleContext {
  public:
    std::string use_label;
    LabContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  LabContext* lab();

  class  GoContext : public antlr4::ParserRuleContext {
  public:
    std::string goto_label;
    GoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  GoContext* go();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    int exp_val_type;
    bool is_const;
    bool is_array;
    bool is_from_symtab;
    size_t num_items;
    std::string result_name;
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpContext() = default;
    void copyFrom(ExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Exp_boolContext : public ExpContext {
  public:
    Exp_boolContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  class  Exp_addContext : public ExpContext {
  public:
    Exp_addContext(ExpContext *ctx);

    AddExpContext *addExp();
  };

  ExpContext* exp();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    std::string truelist;
    std::string falselist;
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();

   
  };

  CondContext* cond();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    bool is_array;
    bool is_const;
    bool is_from_symtab;
    size_t num_items;
    int lval_type;
    std::string result_name;
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    ExpContext *exp();

   
  };

  LValContext* lVal();

  class  PrimaryExpContext : public antlr4::ParserRuleContext {
  public:
    int primary_exp_val_type;
    bool is_const;
    bool is_array;
    bool is_from_symtab;
    size_t num_items;
    std::string result_name;
    PrimaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryExpContext() = default;
    void copyFrom(PrimaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrimaryExp_numContext : public PrimaryExpContext {
  public:
    PrimaryExp_numContext(PrimaryExpContext *ctx);

    NumberContext *number();
  };

  class  PrimaryExp_lvalContext : public PrimaryExpContext {
  public:
    PrimaryExp_lvalContext(PrimaryExpContext *ctx);

    LValContext *lVal();
  };

  class  PrimaryExp_expContext : public PrimaryExpContext {
  public:
    PrimaryExp_expContext(PrimaryExpContext *ctx);

    ExpContext *exp();
  };

  PrimaryExpContext* primaryExp();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    int unary_exp_val_type;
    bool is_const;
    bool is_array;
    bool is_from_symtab;
    size_t num_items;
    std::string result_name;
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryExp_primaryContext : public UnaryExpContext {
  public:
    UnaryExp_primaryContext(UnaryExpContext *ctx);

    PrimaryExpContext *primaryExp();
  };

  class  UnaryExp_uopContext : public UnaryExpContext {
  public:
    UnaryExp_uopContext(UnaryExpContext *ctx);

    UnaryOpContext *unaryOp();
    UnaryExpContext *unaryExp();
  };

  class  UnaryExp_callContext : public UnaryExpContext {
  public:
    UnaryExp_callContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    FuncRParamsContext *funcRParams();
  };

  UnaryExpContext* unaryExp();

  class  UnaryOpContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  UnaryOpContext* unaryOp();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

   
  };

  FuncRParamsContext* funcRParams();

  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    int mul_exp_val_type;
    bool is_const;
    bool is_array;
    bool is_from_symtab;
    size_t num_items;
    std::string result_name;
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MulExpContext() = default;
    void copyFrom(MulExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MulExp_unaryContext : public MulExpContext {
  public:
    MulExp_unaryContext(MulExpContext *ctx);

    UnaryExpContext *unaryExp();
  };

  class  MulExp_mul_unaryContext : public MulExpContext {
  public:
    MulExp_mul_unaryContext(MulExpContext *ctx);

    MulExpContext *mulExp();
    MulOpContext *mulOp();
    UnaryExpContext *unaryExp();
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  MulOpContext : public antlr4::ParserRuleContext {
  public:
    MulOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  MulOpContext* mulOp();

  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    int add_exp_val_type;
    bool is_const;
    bool is_array;
    bool is_from_symtab;
    size_t num_items;
    std::string result_name;
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AddExpContext() = default;
    void copyFrom(AddExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddExp_mulContext : public AddExpContext {
  public:
    AddExp_mulContext(AddExpContext *ctx);

    MulExpContext *mulExp();
  };

  class  AddExp_add_mulContext : public AddExpContext {
  public:
    AddExp_add_mulContext(AddExpContext *ctx);

    AddExpContext *addExp();
    AddOpContext *addOp();
    MulExpContext *mulExp();
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  AddOpContext : public antlr4::ParserRuleContext {
  public:
    AddOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  AddOpContext* addOp();

  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    int rel_exp_val_type;
    bool is_array;
    bool is_const;
    std::string truelist;
    std::string falselist;
    std::string result_name;
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RelExpContext() = default;
    void copyFrom(RelExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RelExp_boolContext : public RelExpContext {
  public:
    RelExp_boolContext(RelExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  class  RelExp_rel_addContext : public RelExpContext {
  public:
    RelExp_rel_addContext(RelExpContext *ctx);

    RelExpContext *relExp();
    RelOpContext *relOp();
    AddExpContext *addExp();
  };

  class  RelExp_addContext : public RelExpContext {
  public:
    RelExp_addContext(RelExpContext *ctx);

    AddExpContext *addExp();
  };

  RelExpContext* relExp();
  RelExpContext* relExp(int precedence);
  class  RelOpContext : public antlr4::ParserRuleContext {
  public:
    RelOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  RelOpContext* relOp();

  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    int eq_exp_val_type;
    bool is_array;
    bool is_const;
    std::string truelist;
    std::string falselist;
    std::string result_name;
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelExpContext *relExp();
    EqExpContext *eqExp();
    EqOpContext *eqOp();

   
  };

  EqExpContext* eqExp();
  EqExpContext* eqExp(int precedence);
  class  EqOpContext : public antlr4::ParserRuleContext {
  public:
    EqOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  EqOpContext* eqOp();

  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    int lAnd_exp_val_type;
    bool is_array;
    bool is_const;
    std::string truelist;
    std::string falselist;
    std::string result_name;
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqExpContext *eqExp();
    LAndExpContext *lAndExp();
    LabContext *lab();

   
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    int lOr_exp_val_type;
    bool is_array;
    bool is_const;
    std::string truelist;
    std::string falselist;
    std::string result_name;
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LAndExpContext *lAndExp();
    LOrExpContext *lOrExp();
    LabContext *lab();

   
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);
  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    int const_type;
    bool is_const;
    bool is_array;
    size_t num_items;
    std::string const_value;
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstExpContext() = default;
    void copyFrom(ConstExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstExp_boolContext : public ConstExpContext {
  public:
    ConstExp_boolContext(ConstExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  class  ConstExp_numContext : public ConstExpContext {
  public:
    ConstExp_numContext(ConstExpContext *ctx);

    NumberContext *number();
  };

  ConstExpContext* constExp();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    int number_type;
    std::string number_value;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumberContext() = default;
    void copyFrom(NumberContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Number_floatContext : public NumberContext {
  public:
    Number_floatContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *FloatConst();
  };

  class  Number_intContext : public NumberContext {
  public:
    Number_intContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *IntConst();
  };

  class  Number_doubleContext : public NumberContext {
  public:
    Number_doubleContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *DoubleConst();
  };

  NumberContext* number();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool mulExpSempred(MulExpContext *_localctx, size_t predicateIndex);
  bool addExpSempred(AddExpContext *_localctx, size_t predicateIndex);
  bool relExpSempred(RelExpContext *_localctx, size_t predicateIndex);
  bool eqExpSempred(EqExpContext *_localctx, size_t predicateIndex);
  bool lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex);
  bool lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

