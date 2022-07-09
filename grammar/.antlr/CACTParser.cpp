
    #include <vector>
    #include <string>


// Generated from /home/ubuntu/cactcompiler/compiler/grammar/CACT.g4 by ANTLR 4.9.2



#include "CACTParser.h"


using namespace antlrcpp;
using namespace antlr4;

CACTParser::CACTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CACTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}


CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0)) {
      setState(74);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(72);
        decl();
        break;
      }

      case 2: {
        setState(73);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}


CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(81);
        constDecl();
        break;
      }

      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(82);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}


CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(CACTParser::T__0);
    setState(86);
    bType();
    setState(87);
    constDef();
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(88);
      match(CACTParser::T__1);
      setState(89);
      constDef();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(95);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}


CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleBType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::copyFrom(ConstDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->id_name = ctx->id_name;
  this->def_val_type = ctx->def_val_type;
  this->is_array = ctx->is_array;
  this->num_items = ctx->num_items;
}

//----------------- ConstDef_initContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDef_initContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstInitValContext* CACTParser::ConstDef_initContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}

tree::TerminalNode* CACTParser::ConstDef_initContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::ConstDef_initContext::ConstDef_initContext(ConstDefContext *ctx) { copyFrom(ctx); }


//----------------- ConstDef_emptyContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDef_emptyContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::ConstDef_emptyContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::ConstDef_emptyContext::ConstDef_emptyContext(ConstDefContext *ctx) { copyFrom(ctx); }


CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDef_emptyContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(99);
      match(CACTParser::Ident);
      setState(103);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(100);
        match(CACTParser::T__7);
        setState(101);
        match(CACTParser::IntConst);
        setState(102);
        match(CACTParser::T__8);
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDef_initContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(105);
      match(CACTParser::Ident);
      setState(109);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(106);
        match(CACTParser::T__7);
        setState(107);
        match(CACTParser::IntConst);
        setState(108);
        match(CACTParser::T__8);
      }
      setState(111);
      match(CACTParser::T__9);
      setState(112);
      constInitVal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

CACTParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstInitValContext::getRuleIndex() const {
  return CACTParser::RuleConstInitVal;
}

void CACTParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->init_val_type = ctx->init_val_type;
  this->num_items = ctx->num_items;
  this->is_array = ctx->is_array;
  this->value_list = ctx->value_list;
}

//----------------- ConstExp_singleContext ------------------------------------------------------------------

CACTParser::ConstExpContext* CACTParser::ConstExp_singleContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstExp_singleContext::ConstExp_singleContext(ConstInitValContext *ctx) { copyFrom(ctx); }


//----------------- ConstExp_arrayContext ------------------------------------------------------------------

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstExp_arrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstExp_arrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::ConstExp_arrayContext::ConstExp_arrayContext(ConstInitValContext *ctx) { copyFrom(ctx); }


CACTParser::ConstInitValContext* CACTParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::BoolConst:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<CACTParser::ConstExp_singleContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(115);
        constExp();
        break;
      }

      case CACTParser::T__10: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<CACTParser::ConstExp_arrayContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(116);
        match(CACTParser::T__10);
        setState(125);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
          | (1ULL << CACTParser::IntConst)
          | (1ULL << CACTParser::FloatConst)
          | (1ULL << CACTParser::DoubleConst))) != 0)) {
          setState(117);
          constExp();
          setState(122);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CACTParser::T__1) {
            setState(118);
            match(CACTParser::T__1);
            setState(119);
            constExp();
            setState(124);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(127);
        match(CACTParser::T__11);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}


CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    bType();
    setState(131);
    varDef();
    setState(136);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(132);
      match(CACTParser::T__1);
      setState(133);
      varDef();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(139);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->id_name = ctx->id_name;
  this->def_val_type = ctx->def_val_type;
  this->is_array = ctx->is_array;
  this->num_items = ctx->num_items;
}

//----------------- VarDef_emptyContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDef_emptyContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::VarDef_emptyContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::VarDef_emptyContext::VarDef_emptyContext(VarDefContext *ctx) { copyFrom(ctx); }


//----------------- VarDef_initContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDef_initContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstInitValContext* CACTParser::VarDef_initContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}

tree::TerminalNode* CACTParser::VarDef_initContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::VarDef_initContext::VarDef_initContext(VarDefContext *ctx) { copyFrom(ctx); }


CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDef_emptyContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(141);
      match(CACTParser::Ident);
      setState(145);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(142);
        match(CACTParser::T__7);
        setState(143);
        match(CACTParser::IntConst);
        setState(144);
        match(CACTParser::T__8);
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDef_initContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(147);
      match(CACTParser::Ident);
      setState(151);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(148);
        match(CACTParser::T__7);
        setState(149);
        match(CACTParser::IntConst);
        setState(150);
        match(CACTParser::T__8);
      }
      setState(153);
      match(CACTParser::T__9);
      setState(154);
      constInitVal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncHeaderContext* CACTParser::FuncDefContext::funcHeader() {
  return getRuleContext<CACTParser::FuncHeaderContext>(0);
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}


CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    funcHeader();
    setState(158);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncHeaderContext ------------------------------------------------------------------

CACTParser::FuncHeaderContext::FuncHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncTypeContext* CACTParser::FuncHeaderContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncHeaderContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncHeaderContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncHeaderContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncHeaderContext::getRuleIndex() const {
  return CACTParser::RuleFuncHeader;
}


CACTParser::FuncHeaderContext* CACTParser::funcHeader() {
  FuncHeaderContext *_localctx = _tracker.createInstance<FuncHeaderContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleFuncHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    funcType();
    setState(161);
    match(CACTParser::Ident);
    setState(162);
    match(CACTParser::T__12);
    setState(171);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0)) {
      setState(163);
      funcFParam();
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CACTParser::T__1) {
        setState(164);
        match(CACTParser::T__1);
        setState(165);
        funcFParam();
        setState(170);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(173);
    match(CACTParser::T__13);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}


CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}

void CACTParser::FuncFParamContext::copyFrom(FuncFParamContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->arg_name = ctx->arg_name;
  this->arg_type = ctx->arg_type;
  this->is_array = ctx->is_array;
}

//----------------- FuncFParam_singleContext ------------------------------------------------------------------

CACTParser::BTypeContext* CACTParser::FuncFParam_singleContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParam_singleContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncFParam_singleContext::FuncFParam_singleContext(FuncFParamContext *ctx) { copyFrom(ctx); }


//----------------- FuncFParam_arrayContext ------------------------------------------------------------------

CACTParser::BTypeContext* CACTParser::FuncFParam_arrayContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParam_arrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncFParam_arrayContext::FuncFParam_arrayContext(FuncFParamContext *ctx) { copyFrom(ctx); }


CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleFuncFParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FuncFParamContext *>(_tracker.createInstance<CACTParser::FuncFParam_singleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(177);
      bType();
      setState(178);
      match(CACTParser::Ident);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FuncFParamContext *>(_tracker.createInstance<CACTParser::FuncFParam_arrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(180);
      bType();
      setState(181);
      match(CACTParser::Ident);
      setState(182);
      match(CACTParser::T__7);
      setState(183);
      match(CACTParser::T__8);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}


CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    match(CACTParser::T__10);
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__10)
      | (1ULL << CACTParser::T__12)
      | (1ULL << CACTParser::T__15)
      | (1ULL << CACTParser::T__17)
      | (1ULL << CACTParser::T__18)
      | (1ULL << CACTParser::T__19)
      | (1ULL << CACTParser::T__20)
      | (1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(188);
      blockItem();
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(194);
    match(CACTParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}


CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(198);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(196);
        decl();
        break;
      }

      case CACTParser::T__2:
      case CACTParser::T__10:
      case CACTParser::T__12:
      case CACTParser::T__15:
      case CACTParser::T__17:
      case CACTParser::T__18:
      case CACTParser::T__19:
      case CACTParser::T__20:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::BoolConst:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 2);
        setState(197);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->allow_break = ctx->allow_break;
  this->allow_continue = ctx->allow_continue;
  this->allow_return = ctx->allow_return;
  this->stmt_type = ctx->stmt_type;
  this->stmt_val_type = ctx->stmt_val_type;
  this->actual_has_return = ctx->actual_has_return;
  this->actual_return_type = ctx->actual_return_type;
  this->else_flag = ctx->else_flag;
  this->while_begin = ctx->while_begin;
  this->while_end = ctx->while_end;
  this->nextlist = ctx->nextlist;
}

//----------------- Stmt_ifContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::Stmt_ifContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

std::vector<CACTParser::LabContext *> CACTParser::Stmt_ifContext::lab() {
  return getRuleContexts<CACTParser::LabContext>();
}

CACTParser::LabContext* CACTParser::Stmt_ifContext::lab(size_t i) {
  return getRuleContext<CACTParser::LabContext>(i);
}

std::vector<CACTParser::StmtContext *> CACTParser::Stmt_ifContext::stmt() {
  return getRuleContexts<CACTParser::StmtContext>();
}

CACTParser::StmtContext* CACTParser::Stmt_ifContext::stmt(size_t i) {
  return getRuleContext<CACTParser::StmtContext>(i);
}

CACTParser::GoContext* CACTParser::Stmt_ifContext::go() {
  return getRuleContext<CACTParser::GoContext>(0);
}

CACTParser::Stmt_ifContext::Stmt_ifContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- Stmt_blockContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::Stmt_blockContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::Stmt_blockContext::Stmt_blockContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- Stmt_breakContext ------------------------------------------------------------------

CACTParser::Stmt_breakContext::Stmt_breakContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- Stmt_continueContext ------------------------------------------------------------------

CACTParser::Stmt_continueContext::Stmt_continueContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- Stmt_whileContext ------------------------------------------------------------------

std::vector<CACTParser::LabContext *> CACTParser::Stmt_whileContext::lab() {
  return getRuleContexts<CACTParser::LabContext>();
}

CACTParser::LabContext* CACTParser::Stmt_whileContext::lab(size_t i) {
  return getRuleContext<CACTParser::LabContext>(i);
}

CACTParser::CondContext* CACTParser::Stmt_whileContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::Stmt_whileContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::GoContext* CACTParser::Stmt_whileContext::go() {
  return getRuleContext<CACTParser::GoContext>(0);
}

CACTParser::Stmt_whileContext::Stmt_whileContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- Stmt_assignContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::Stmt_assignContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::Stmt_assignContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::Stmt_assignContext::Stmt_assignContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- Stmt_returnContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::Stmt_returnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::Stmt_returnContext::Stmt_returnContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- Stmt_expContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::Stmt_expContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::Stmt_expContext::Stmt_expContext(StmtContext *ctx) { copyFrom(ctx); }


CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_assignContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(200);
      lVal();
      setState(201);
      match(CACTParser::T__9);
      setState(202);
      exp();
      setState(203);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_expContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(206);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(205);
        exp();
      }
      setState(208);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_blockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(209);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_ifContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(210);
      match(CACTParser::T__15);
      setState(211);
      match(CACTParser::T__12);
      setState(212);
      cond();
      setState(213);
      match(CACTParser::T__13);
      setState(214);
      lab();
      setState(215);
      stmt();
      setState(221);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(216);
        go();
        setState(217);
        lab();
        setState(218);
        match(CACTParser::T__16);
        setState(219);
        stmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_whileContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(223);
      match(CACTParser::T__17);
      setState(224);
      lab();
      setState(225);
      match(CACTParser::T__12);
      setState(226);
      cond();
      setState(227);
      match(CACTParser::T__13);
      setState(228);
      lab();
      setState(229);
      stmt();
      setState(230);
      go();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_breakContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(232);
      match(CACTParser::T__18);
      setState(233);
      match(CACTParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_continueContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(234);
      match(CACTParser::T__19);
      setState(235);
      match(CACTParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::Stmt_returnContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(236);
      match(CACTParser::T__20);
      setState(238);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(237);
        exp();
      }
      setState(240);
      match(CACTParser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabContext ------------------------------------------------------------------

CACTParser::LabContext::LabContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LabContext::getRuleIndex() const {
  return CACTParser::RuleLab;
}


CACTParser::LabContext* CACTParser::lab() {
  LabContext *_localctx = _tracker.createInstance<LabContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleLab);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GoContext ------------------------------------------------------------------

CACTParser::GoContext::GoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::GoContext::getRuleIndex() const {
  return CACTParser::RuleGo;
}


CACTParser::GoContext* CACTParser::go() {
  GoContext *_localctx = _tracker.createInstance<GoContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleGo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->exp_val_type = ctx->exp_val_type;
  this->is_const = ctx->is_const;
  this->is_array = ctx->is_array;
  this->is_from_symtab = ctx->is_from_symtab;
  this->num_items = ctx->num_items;
  this->result_name = ctx->result_name;
}

//----------------- Exp_boolContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::Exp_boolContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::Exp_boolContext::Exp_boolContext(ExpContext *ctx) { copyFrom(ctx); }


//----------------- Exp_addContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::Exp_addContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::Exp_addContext::Exp_addContext(ExpContext *ctx) { copyFrom(ctx); }


CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(249);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::Exp_addContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(247);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::Exp_boolContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(248);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}


CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::LValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::LValContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}


CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(CACTParser::Ident);
    setState(258);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(254);
      match(CACTParser::T__7);
      setState(255);
      exp();
      setState(256);
      match(CACTParser::T__8);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->primary_exp_val_type = ctx->primary_exp_val_type;
  this->is_const = ctx->is_const;
  this->is_array = ctx->is_array;
  this->is_from_symtab = ctx->is_from_symtab;
  this->num_items = ctx->num_items;
  this->result_name = ctx->result_name;
}

//----------------- PrimaryExp_numContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::PrimaryExp_numContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::PrimaryExp_numContext::PrimaryExp_numContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryExp_lvalContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::PrimaryExp_lvalContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::PrimaryExp_lvalContext::PrimaryExp_lvalContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryExp_expContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::PrimaryExp_expContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::PrimaryExp_expContext::PrimaryExp_expContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RulePrimaryExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExp_expContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(260);
        match(CACTParser::T__12);
        setState(261);
        exp();
        setState(262);
        match(CACTParser::T__13);
        break;
      }

      case CACTParser::Ident: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExp_lvalContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(264);
        lVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExp_numContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(265);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->unary_exp_val_type = ctx->unary_exp_val_type;
  this->is_const = ctx->is_const;
  this->is_array = ctx->is_array;
  this->is_from_symtab = ctx->is_from_symtab;
  this->num_items = ctx->num_items;
  this->result_name = ctx->result_name;
}

//----------------- UnaryExp_primaryContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::UnaryExp_primaryContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::UnaryExp_primaryContext::UnaryExp_primaryContext(UnaryExpContext *ctx) { copyFrom(ctx); }


//----------------- UnaryExp_uopContext ------------------------------------------------------------------

CACTParser::UnaryOpContext* CACTParser::UnaryExp_uopContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryExp_uopContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::UnaryExp_uopContext::UnaryExp_uopContext(UnaryExpContext *ctx) { copyFrom(ctx); }


//----------------- UnaryExp_callContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::UnaryExp_callContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::UnaryExp_callContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::UnaryExp_callContext::UnaryExp_callContext(UnaryExpContext *ctx) { copyFrom(ctx); }


CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExp_primaryContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(268);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExp_callContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(269);
      match(CACTParser::Ident);
      setState(270);
      match(CACTParser::T__12);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(271);
        funcRParams();
      }
      setState(274);
      match(CACTParser::T__13);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExp_uopContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(275);
      unaryOp();
      setState(276);
      unaryExp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryOpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryOp;
}


CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}


CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 46, CACTParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    exp();
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(283);
      match(CACTParser::T__1);
      setState(284);
      exp();
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->mul_exp_val_type = ctx->mul_exp_val_type;
  this->is_const = ctx->is_const;
  this->is_array = ctx->is_array;
  this->is_from_symtab = ctx->is_from_symtab;
  this->num_items = ctx->num_items;
  this->result_name = ctx->result_name;
}

//----------------- MulExp_unaryContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::MulExp_unaryContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExp_unaryContext::MulExp_unaryContext(MulExpContext *ctx) { copyFrom(ctx); }


//----------------- MulExp_mul_unaryContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::MulExp_mul_unaryContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::MulOpContext* CACTParser::MulExp_mul_unaryContext::mulOp() {
  return getRuleContext<CACTParser::MulOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::MulExp_mul_unaryContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExp_mul_unaryContext::MulExp_mul_unaryContext(MulExpContext *ctx) { copyFrom(ctx); }



CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, CACTParser::RuleMulExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulExp_unaryContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(291);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulExp_mul_unaryContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(293);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(294);
        mulOp();
        setState(295);
        unaryExp(); 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

CACTParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulOpContext::getRuleIndex() const {
  return CACTParser::RuleMulOp;
}


CACTParser::MulOpContext* CACTParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 50, CACTParser::RuleMulOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__24)
      | (1ULL << CACTParser::T__25)
      | (1ULL << CACTParser::T__26))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->add_exp_val_type = ctx->add_exp_val_type;
  this->is_const = ctx->is_const;
  this->is_array = ctx->is_array;
  this->is_from_symtab = ctx->is_from_symtab;
  this->num_items = ctx->num_items;
  this->result_name = ctx->result_name;
}

//----------------- AddExp_mulContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::AddExp_mulContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExp_mulContext::AddExp_mulContext(AddExpContext *ctx) { copyFrom(ctx); }


//----------------- AddExp_add_mulContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::AddExp_add_mulContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::AddOpContext* CACTParser::AddExp_add_mulContext::addOp() {
  return getRuleContext<CACTParser::AddOpContext>(0);
}

CACTParser::MulExpContext* CACTParser::AddExp_add_mulContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExp_add_mulContext::AddExp_add_mulContext(AddExpContext *ctx) { copyFrom(ctx); }



CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, CACTParser::RuleAddExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AddExp_mulContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(305);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(313);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddExp_add_mulContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(307);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(308);
        addOp();
        setState(309);
        mulExp(0); 
      }
      setState(315);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

CACTParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddOpContext::getRuleIndex() const {
  return CACTParser::RuleAddOp;
}


CACTParser::AddOpContext* CACTParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 54, CACTParser::RuleAddOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    _la = _input->LA(1);
    if (!(_la == CACTParser::T__21

    || _la == CACTParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->rel_exp_val_type = ctx->rel_exp_val_type;
  this->is_array = ctx->is_array;
  this->is_const = ctx->is_const;
  this->truelist = ctx->truelist;
  this->falselist = ctx->falselist;
  this->result_name = ctx->result_name;
}

//----------------- RelExp_boolContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RelExp_boolContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::RelExp_boolContext::RelExp_boolContext(RelExpContext *ctx) { copyFrom(ctx); }


//----------------- RelExp_rel_addContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::RelExp_rel_addContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::RelOpContext* CACTParser::RelExp_rel_addContext::relOp() {
  return getRuleContext<CACTParser::RelOpContext>(0);
}

CACTParser::AddExpContext* CACTParser::RelExp_rel_addContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExp_rel_addContext::RelExp_rel_addContext(RelExpContext *ctx) { copyFrom(ctx); }


//----------------- RelExp_addContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::RelExp_addContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExp_addContext::RelExp_addContext(RelExpContext *ctx) { copyFrom(ctx); }



CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleRelExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<RelExp_addContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(319);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<RelExp_boolContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(320);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(329);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<RelExp_rel_addContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(323);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(324);
        relOp();
        setState(325);
        addExp(0); 
      }
      setState(331);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

CACTParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelOpContext::getRuleIndex() const {
  return CACTParser::RuleRelOp;
}


CACTParser::RelOpContext* CACTParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 58, CACTParser::RuleRelOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__27)
      | (1ULL << CACTParser::T__28)
      | (1ULL << CACTParser::T__29)
      | (1ULL << CACTParser::T__30))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::RelExpContext* CACTParser::EqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::EqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::EqOpContext* CACTParser::EqExpContext::eqOp() {
  return getRuleContext<CACTParser::EqOpContext>(0);
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}



CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, CACTParser::RuleEqExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(335);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(343);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqExp);
        setState(337);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(338);
        eqOp();
        setState(339);
        relExp(0); 
      }
      setState(345);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqOpContext ------------------------------------------------------------------

CACTParser::EqOpContext::EqOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqOpContext::getRuleIndex() const {
  return CACTParser::RuleEqOp;
}


CACTParser::EqOpContext* CACTParser::eqOp() {
  EqOpContext *_localctx = _tracker.createInstance<EqOpContext>(_ctx, getState());
  enterRule(_localctx, 62, CACTParser::RuleEqOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    _la = _input->LA(1);
    if (!(_la == CACTParser::T__31

    || _la == CACTParser::T__32)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::EqExpContext* CACTParser::LAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LabContext* CACTParser::LAndExpContext::lab() {
  return getRuleContext<CACTParser::LabContext>(0);
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}



CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, CACTParser::RuleLAndExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(349);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(358);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LAndExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLAndExp);
        setState(351);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(352);
        lab();
        setState(353);
        match(CACTParser::T__33);
        setState(354);
        eqExp(0); 
      }
      setState(360);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LAndExpContext* CACTParser::LOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpContext* CACTParser::LOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

CACTParser::LabContext* CACTParser::LOrExpContext::lab() {
  return getRuleContext<CACTParser::LabContext>(0);
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}



CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, CACTParser::RuleLOrExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(362);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(371);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LOrExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLOrExp);
        setState(364);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(365);
        lab();
        setState(366);
        match(CACTParser::T__34);
        setState(367);
        lAndExp(0); 
      }
      setState(373);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->const_type = ctx->const_type;
  this->is_const = ctx->is_const;
  this->is_array = ctx->is_array;
  this->num_items = ctx->num_items;
  this->const_value = ctx->const_value;
}

//----------------- ConstExp_boolContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstExp_boolContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ConstExp_boolContext::ConstExp_boolContext(ConstExpContext *ctx) { copyFrom(ctx); }


//----------------- ConstExp_numContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::ConstExp_numContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::ConstExp_numContext::ConstExp_numContext(ConstExpContext *ctx) { copyFrom(ctx); }


CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 68, CACTParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExp_numContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(374);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExp_boolContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(375);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CACTParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::NumberContext::getRuleIndex() const {
  return CACTParser::RuleNumber;
}

void CACTParser::NumberContext::copyFrom(NumberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->number_type = ctx->number_type;
  this->number_value = ctx->number_value;
}

//----------------- Number_floatContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::Number_floatContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}

CACTParser::Number_floatContext::Number_floatContext(NumberContext *ctx) { copyFrom(ctx); }


//----------------- Number_intContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::Number_intContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::Number_intContext::Number_intContext(NumberContext *ctx) { copyFrom(ctx); }


//----------------- Number_doubleContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::Number_doubleContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

CACTParser::Number_doubleContext::Number_doubleContext(NumberContext *ctx) { copyFrom(ctx); }


CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 70, CACTParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::Number_intContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(378);
        match(CACTParser::IntConst);
        break;
      }

      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::Number_doubleContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(379);
        match(CACTParser::DoubleConst);
        break;
      }

      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::Number_floatContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(380);
        match(CACTParser::FloatConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 24: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 26: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 28: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 30: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 32: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 33: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
  "varDecl", "varDef", "funcDef", "funcHeader", "funcType", "funcFParam", 
  "block", "blockItem", "stmt", "lab", "go", "exp", "cond", "lVal", "primaryExp", 
  "unaryExp", "unaryOp", "funcRParams", "mulExp", "mulOp", "addExp", "addOp", 
  "relExp", "relOp", "eqExp", "eqOp", "lAndExp", "lOrExp", "constExp", "number"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "'const'", "','", "';'", "'int'", "'bool'", "'float'", "'double'", 
  "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", "'void'", "'if'", "'else'", 
  "'while'", "'break'", "'continue'", "'return'", "'+'", "'-'", "'!'", "'*'", 
  "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'"
};

std::vector<std::string> CACTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "BoolConst", "Ident", "IntConst", "FloatConst", "DoubleConst", "NewLine", 
  "WhiteSpace", "BlockComment", "LineComment"
};

dfa::Vocabulary CACTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CACTParser::_tokenNames;

CACTParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x2e, 0x182, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x3, 0x2, 
       0x3, 0x2, 0x7, 0x2, 0x4d, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x50, 0xb, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x56, 0xa, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 
       0x5d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x60, 0xb, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x5, 0x6, 0x6a, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x5, 0x6, 0x70, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x74, 0xa, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
       0x7b, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x7e, 0xb, 0x7, 0x5, 0x7, 0x80, 
       0xa, 0x7, 0x3, 0x7, 0x5, 0x7, 0x83, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x89, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
       0x8c, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x5, 0x9, 0x94, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x5, 0x9, 0x9a, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
       0x9e, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xa9, 0xa, 0xb, 
       0xc, 0xb, 0xe, 0xb, 0xac, 0xb, 0xb, 0x5, 0xb, 0xae, 0xa, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xbc, 
       0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xc0, 0xa, 0xe, 0xc, 0xe, 
       0xe, 0xe, 0xc3, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
       0x5, 0xf, 0xc9, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xd1, 0xa, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 
       0x10, 0xe0, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
       0xf1, 0xa, 0x10, 0x3, 0x10, 0x5, 0x10, 0xf4, 0xa, 0x10, 0x3, 0x11, 
       0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 
       0xfc, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x105, 0xa, 0x15, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
       0x10d, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 
       0x17, 0x113, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x5, 0x17, 0x119, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x7, 0x19, 0x120, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
       0x123, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x12c, 0xa, 0x1a, 0xc, 0x1a, 
       0xe, 0x1a, 0x12f, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 
       0x1c, 0x13a, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x13d, 0xb, 0x1c, 0x3, 
       0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x144, 
       0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 
       0x14a, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x14d, 0xb, 0x1e, 0x3, 0x1f, 
       0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x158, 0xa, 0x20, 0xc, 0x20, 0xe, 
       0x20, 0x15b, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
       0x7, 0x22, 0x167, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x16a, 0xb, 0x22, 
       0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x174, 0xa, 0x23, 0xc, 0x23, 0xe, 
       0x23, 0x177, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x17b, 0xa, 
       0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x180, 0xa, 0x25, 
       0x3, 0x25, 0x2, 0x8, 0x32, 0x36, 0x3a, 0x3e, 0x42, 0x44, 0x26, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
       0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
       0x48, 0x2, 0x9, 0x3, 0x2, 0x6, 0x9, 0x4, 0x2, 0x6, 0x9, 0x11, 0x11, 
       0x3, 0x2, 0x18, 0x1a, 0x3, 0x2, 0x1b, 0x1d, 0x3, 0x2, 0x18, 0x19, 
       0x3, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 0x2, 0x18c, 0x2, 0x4e, 
       0x3, 0x2, 0x2, 0x2, 0x4, 0x55, 0x3, 0x2, 0x2, 0x2, 0x6, 0x57, 0x3, 
       0x2, 0x2, 0x2, 0x8, 0x63, 0x3, 0x2, 0x2, 0x2, 0xa, 0x73, 0x3, 0x2, 
       0x2, 0x2, 0xc, 0x82, 0x3, 0x2, 0x2, 0x2, 0xe, 0x84, 0x3, 0x2, 0x2, 
       0x2, 0x10, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9f, 0x3, 0x2, 0x2, 0x2, 
       0x14, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x18, 
       0xbb, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc8, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x20, 0xf5, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x24, 0xfb, 0x3, 0x2, 
       0x2, 0x2, 0x26, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x28, 0xff, 0x3, 0x2, 0x2, 
       0x2, 0x2a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x118, 0x3, 0x2, 0x2, 
       0x2, 0x2e, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x30, 0x11c, 0x3, 0x2, 0x2, 
       0x2, 0x32, 0x124, 0x3, 0x2, 0x2, 0x2, 0x34, 0x130, 0x3, 0x2, 0x2, 
       0x2, 0x36, 0x132, 0x3, 0x2, 0x2, 0x2, 0x38, 0x13e, 0x3, 0x2, 0x2, 
       0x2, 0x3a, 0x143, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x14e, 0x3, 0x2, 0x2, 
       0x2, 0x3e, 0x150, 0x3, 0x2, 0x2, 0x2, 0x40, 0x15c, 0x3, 0x2, 0x2, 
       0x2, 0x42, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x44, 0x16b, 0x3, 0x2, 0x2, 
       0x2, 0x46, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x17f, 0x3, 0x2, 0x2, 
       0x2, 0x4a, 0x4d, 0x5, 0x4, 0x3, 0x2, 0x4b, 0x4d, 0x5, 0x12, 0xa, 
       0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 
       0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 
       0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x2, 0x2, 0x3, 0x52, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x53, 0x56, 0x5, 0x6, 0x4, 0x2, 0x54, 0x56, 0x5, 0xe, 
       0x8, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 
       0x2, 0x56, 0x5, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0x3, 0x2, 0x2, 
       0x58, 0x59, 0x5, 0x8, 0x5, 0x2, 0x59, 0x5e, 0x5, 0xa, 0x6, 0x2, 0x5a, 
       0x5b, 0x7, 0x4, 0x2, 0x2, 0x5b, 0x5d, 0x5, 0xa, 0x6, 0x2, 0x5c, 0x5a, 
       0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x61, 0x3, 0x2, 
       0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x5, 0x2, 
       0x2, 0x62, 0x7, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x9, 0x2, 0x2, 0x2, 
       0x64, 0x9, 0x3, 0x2, 0x2, 0x2, 0x65, 0x69, 0x7, 0x27, 0x2, 0x2, 0x66, 
       0x67, 0x7, 0xa, 0x2, 0x2, 0x67, 0x68, 0x7, 0x28, 0x2, 0x2, 0x68, 
       0x6a, 0x7, 0xb, 0x2, 0x2, 0x69, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 
       0x3, 0x2, 0x2, 0x2, 0x6a, 0x74, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6f, 0x7, 
       0x27, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0xa, 0x2, 0x2, 0x6d, 0x6e, 0x7, 
       0x28, 0x2, 0x2, 0x6e, 0x70, 0x7, 0xb, 0x2, 0x2, 0x6f, 0x6c, 0x3, 
       0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 
       0x2, 0x2, 0x71, 0x72, 0x7, 0xc, 0x2, 0x2, 0x72, 0x74, 0x5, 0xc, 0x7, 
       0x2, 0x73, 0x65, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6b, 0x3, 0x2, 0x2, 0x2, 
       0x74, 0xb, 0x3, 0x2, 0x2, 0x2, 0x75, 0x83, 0x5, 0x46, 0x24, 0x2, 
       0x76, 0x7f, 0x7, 0xd, 0x2, 0x2, 0x77, 0x7c, 0x5, 0x46, 0x24, 0x2, 
       0x78, 0x79, 0x7, 0x4, 0x2, 0x2, 0x79, 0x7b, 0x5, 0x46, 0x24, 0x2, 
       0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7c, 
       0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x80, 
       0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x77, 0x3, 
       0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 
       0x2, 0x2, 0x81, 0x83, 0x7, 0xe, 0x2, 0x2, 0x82, 0x75, 0x3, 0x2, 0x2, 
       0x2, 0x82, 0x76, 0x3, 0x2, 0x2, 0x2, 0x83, 0xd, 0x3, 0x2, 0x2, 0x2, 
       0x84, 0x85, 0x5, 0x8, 0x5, 0x2, 0x85, 0x8a, 0x5, 0x10, 0x9, 0x2, 
       0x86, 0x87, 0x7, 0x4, 0x2, 0x2, 0x87, 0x89, 0x5, 0x10, 0x9, 0x2, 
       0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 
       0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 
       0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 
       0x5, 0x2, 0x2, 0x8e, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x93, 0x7, 0x27, 
       0x2, 0x2, 0x90, 0x91, 0x7, 0xa, 0x2, 0x2, 0x91, 0x92, 0x7, 0x28, 
       0x2, 0x2, 0x92, 0x94, 0x7, 0xb, 0x2, 0x2, 0x93, 0x90, 0x3, 0x2, 0x2, 
       0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x9e, 0x3, 0x2, 0x2, 0x2, 
       0x95, 0x99, 0x7, 0x27, 0x2, 0x2, 0x96, 0x97, 0x7, 0xa, 0x2, 0x2, 
       0x97, 0x98, 0x7, 0x28, 0x2, 0x2, 0x98, 0x9a, 0x7, 0xb, 0x2, 0x2, 
       0x99, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0xc, 0x2, 0x2, 0x9c, 0x9e, 
       0x5, 0xc, 0x7, 0x2, 0x9d, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x95, 0x3, 
       0x2, 0x2, 0x2, 0x9e, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x5, 0x14, 
       0xb, 0x2, 0xa0, 0xa1, 0x5, 0x1a, 0xe, 0x2, 0xa1, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0xa2, 0xa3, 0x5, 0x16, 0xc, 0x2, 0xa3, 0xa4, 0x7, 0x27, 
       0x2, 0x2, 0xa4, 0xad, 0x7, 0xf, 0x2, 0x2, 0xa5, 0xaa, 0x5, 0x18, 
       0xd, 0x2, 0xa6, 0xa7, 0x7, 0x4, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x18, 
       0xd, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 
       0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 
       0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 
       0xa5, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 
       0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x10, 0x2, 0x2, 0xb0, 0x15, 
       0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x9, 0x3, 0x2, 0x2, 0xb2, 0x17, 0x3, 
       0x2, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x8, 0x5, 0x2, 0xb4, 0xb5, 0x7, 0x27, 
       0x2, 0x2, 0xb5, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x8, 0x5, 
       0x2, 0xb7, 0xb8, 0x7, 0x27, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0xa, 0x2, 
       0x2, 0xb9, 0xba, 0x7, 0xb, 0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 
       0xbb, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xbc, 
       0x19, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc1, 0x7, 0xd, 0x2, 0x2, 0xbe, 0xc0, 
       0x5, 0x1c, 0xf, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc3, 
       0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 
       0x2, 0x2, 0x2, 0xc2, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 
       0x2, 0x2, 0xc4, 0xc5, 0x7, 0xe, 0x2, 0x2, 0xc5, 0x1b, 0x3, 0x2, 0x2, 
       0x2, 0xc6, 0xc9, 0x5, 0x4, 0x3, 0x2, 0xc7, 0xc9, 0x5, 0x1e, 0x10, 
       0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 
       0xc9, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x28, 0x15, 0x2, 
       0xcb, 0xcc, 0x7, 0xc, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x24, 0x13, 0x2, 
       0xcd, 0xce, 0x7, 0x5, 0x2, 0x2, 0xce, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xcf, 
       0xd1, 0x5, 0x24, 0x13, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 
       0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xf4, 
       0x7, 0x5, 0x2, 0x2, 0xd3, 0xf4, 0x5, 0x1a, 0xe, 0x2, 0xd4, 0xd5, 
       0x7, 0x12, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0xf, 0x2, 0x2, 0xd6, 0xd7, 
       0x5, 0x26, 0x14, 0x2, 0xd7, 0xd8, 0x7, 0x10, 0x2, 0x2, 0xd8, 0xd9, 
       0x5, 0x20, 0x11, 0x2, 0xd9, 0xdf, 0x5, 0x1e, 0x10, 0x2, 0xda, 0xdb, 
       0x5, 0x22, 0x12, 0x2, 0xdb, 0xdc, 0x5, 0x20, 0x11, 0x2, 0xdc, 0xdd, 
       0x7, 0x13, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x1e, 0x10, 0x2, 0xde, 0xe0, 
       0x3, 0x2, 0x2, 0x2, 0xdf, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 
       0x2, 0x2, 0x2, 0xe0, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x14, 
       0x2, 0x2, 0xe2, 0xe3, 0x5, 0x20, 0x11, 0x2, 0xe3, 0xe4, 0x7, 0xf, 
       0x2, 0x2, 0xe4, 0xe5, 0x5, 0x26, 0x14, 0x2, 0xe5, 0xe6, 0x7, 0x10, 
       0x2, 0x2, 0xe6, 0xe7, 0x5, 0x20, 0x11, 0x2, 0xe7, 0xe8, 0x5, 0x1e, 
       0x10, 0x2, 0xe8, 0xe9, 0x5, 0x22, 0x12, 0x2, 0xe9, 0xf4, 0x3, 0x2, 
       0x2, 0x2, 0xea, 0xeb, 0x7, 0x15, 0x2, 0x2, 0xeb, 0xf4, 0x7, 0x5, 
       0x2, 0x2, 0xec, 0xed, 0x7, 0x16, 0x2, 0x2, 0xed, 0xf4, 0x7, 0x5, 
       0x2, 0x2, 0xee, 0xf0, 0x7, 0x17, 0x2, 0x2, 0xef, 0xf1, 0x5, 0x24, 
       0x13, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 
       0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf4, 0x7, 0x5, 0x2, 
       0x2, 0xf3, 0xca, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xd0, 0x3, 0x2, 0x2, 0x2, 
       0xf3, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xf3, 
       0xe1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xea, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xec, 
       0x3, 0x2, 0x2, 0x2, 0xf3, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x1f, 0x3, 
       0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x21, 0x3, 0x2, 
       0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x23, 0x3, 0x2, 0x2, 
       0x2, 0xf9, 0xfc, 0x5, 0x36, 0x1c, 0x2, 0xfa, 0xfc, 0x7, 0x26, 0x2, 
       0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfa, 0x3, 0x2, 0x2, 0x2, 
       0xfc, 0x25, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x44, 0x23, 0x2, 
       0xfe, 0x27, 0x3, 0x2, 0x2, 0x2, 0xff, 0x104, 0x7, 0x27, 0x2, 0x2, 
       0x100, 0x101, 0x7, 0xa, 0x2, 0x2, 0x101, 0x102, 0x5, 0x24, 0x13, 
       0x2, 0x102, 0x103, 0x7, 0xb, 0x2, 0x2, 0x103, 0x105, 0x3, 0x2, 0x2, 
       0x2, 0x104, 0x100, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 
       0x2, 0x105, 0x29, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x7, 0xf, 0x2, 
       0x2, 0x107, 0x108, 0x5, 0x24, 0x13, 0x2, 0x108, 0x109, 0x7, 0x10, 
       0x2, 0x2, 0x109, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 0x5, 0x28, 
       0x15, 0x2, 0x10b, 0x10d, 0x5, 0x48, 0x25, 0x2, 0x10c, 0x106, 0x3, 
       0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10b, 0x3, 
       0x2, 0x2, 0x2, 0x10d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x119, 0x5, 
       0x2a, 0x16, 0x2, 0x10f, 0x110, 0x7, 0x27, 0x2, 0x2, 0x110, 0x112, 
       0x7, 0xf, 0x2, 0x2, 0x111, 0x113, 0x5, 0x30, 0x19, 0x2, 0x112, 0x111, 
       0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 
       0x3, 0x2, 0x2, 0x2, 0x114, 0x119, 0x7, 0x10, 0x2, 0x2, 0x115, 0x116, 
       0x5, 0x2e, 0x18, 0x2, 0x116, 0x117, 0x5, 0x2c, 0x17, 0x2, 0x117, 
       0x119, 0x3, 0x2, 0x2, 0x2, 0x118, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x118, 
       0x10f, 0x3, 0x2, 0x2, 0x2, 0x118, 0x115, 0x3, 0x2, 0x2, 0x2, 0x119, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x9, 0x4, 0x2, 0x2, 0x11b, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x121, 0x5, 0x24, 0x13, 0x2, 0x11d, 
       0x11e, 0x7, 0x4, 0x2, 0x2, 0x11e, 0x120, 0x5, 0x24, 0x13, 0x2, 0x11f, 
       0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 0x3, 0x2, 0x2, 0x2, 0x121, 
       0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 
       0x125, 0x8, 0x1a, 0x1, 0x2, 0x125, 0x126, 0x5, 0x2c, 0x17, 0x2, 0x126, 
       0x12d, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0xc, 0x3, 0x2, 0x2, 0x128, 
       0x129, 0x5, 0x34, 0x1b, 0x2, 0x129, 0x12a, 0x5, 0x2c, 0x17, 0x2, 
       0x12a, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x127, 0x3, 0x2, 0x2, 0x2, 
       0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 
       0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x33, 0x3, 0x2, 0x2, 0x2, 
       0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x9, 0x5, 0x2, 0x2, 
       0x131, 0x35, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x8, 0x1c, 0x1, 0x2, 
       0x133, 0x134, 0x5, 0x32, 0x1a, 0x2, 0x134, 0x13b, 0x3, 0x2, 0x2, 
       0x2, 0x135, 0x136, 0xc, 0x3, 0x2, 0x2, 0x136, 0x137, 0x5, 0x38, 0x1d, 
       0x2, 0x137, 0x138, 0x5, 0x32, 0x1a, 0x2, 0x138, 0x13a, 0x3, 0x2, 
       0x2, 0x2, 0x139, 0x135, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 
       0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 
       0x2, 0x2, 0x13c, 0x37, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 
       0x2, 0x2, 0x13e, 0x13f, 0x9, 0x6, 0x2, 0x2, 0x13f, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0x140, 0x141, 0x8, 0x1e, 0x1, 0x2, 0x141, 0x144, 0x5, 0x36, 
       0x1c, 0x2, 0x142, 0x144, 0x7, 0x26, 0x2, 0x2, 0x143, 0x140, 0x3, 
       0x2, 0x2, 0x2, 0x143, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x14b, 0x3, 
       0x2, 0x2, 0x2, 0x145, 0x146, 0xc, 0x4, 0x2, 0x2, 0x146, 0x147, 0x5, 
       0x3c, 0x1f, 0x2, 0x147, 0x148, 0x5, 0x36, 0x1c, 0x2, 0x148, 0x14a, 
       0x3, 0x2, 0x2, 0x2, 0x149, 0x145, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 
       0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x14c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 
       0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x9, 0x7, 0x2, 0x2, 0x14f, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x8, 0x20, 0x1, 0x2, 0x151, 0x152, 
       0x5, 0x3a, 0x1e, 0x2, 0x152, 0x159, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 
       0xc, 0x3, 0x2, 0x2, 0x154, 0x155, 0x5, 0x40, 0x21, 0x2, 0x155, 0x156, 
       0x5, 0x3a, 0x1e, 0x2, 0x156, 0x158, 0x3, 0x2, 0x2, 0x2, 0x157, 0x153, 
       0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x157, 
       0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x3f, 
       0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
       0x9, 0x8, 0x2, 0x2, 0x15d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 
       0x8, 0x22, 0x1, 0x2, 0x15f, 0x160, 0x5, 0x3e, 0x20, 0x2, 0x160, 0x168, 
       0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0xc, 0x3, 0x2, 0x2, 0x162, 0x163, 
       0x5, 0x20, 0x11, 0x2, 0x163, 0x164, 0x7, 0x24, 0x2, 0x2, 0x164, 0x165, 
       0x5, 0x3e, 0x20, 0x2, 0x165, 0x167, 0x3, 0x2, 0x2, 0x2, 0x166, 0x161, 
       0x3, 0x2, 0x2, 0x2, 0x167, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x168, 0x166, 
       0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 
       0x8, 0x23, 0x1, 0x2, 0x16c, 0x16d, 0x5, 0x42, 0x22, 0x2, 0x16d, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0xc, 0x3, 0x2, 0x2, 0x16f, 0x170, 
       0x5, 0x20, 0x11, 0x2, 0x170, 0x171, 0x7, 0x25, 0x2, 0x2, 0x171, 0x172, 
       0x5, 0x42, 0x22, 0x2, 0x172, 0x174, 0x3, 0x2, 0x2, 0x2, 0x173, 0x16e, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x177, 0x3, 0x2, 0x2, 0x2, 0x175, 0x173, 
       0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x177, 0x175, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17b, 
       0x5, 0x48, 0x25, 0x2, 0x179, 0x17b, 0x7, 0x26, 0x2, 0x2, 0x17a, 0x178, 
       0x3, 0x2, 0x2, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x17c, 0x180, 0x7, 0x28, 0x2, 0x2, 0x17d, 0x180, 
       0x7, 0x2a, 0x2, 0x2, 0x17e, 0x180, 0x7, 0x29, 0x2, 0x2, 0x17f, 0x17c, 
       0x3, 0x2, 0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x180, 0x49, 0x3, 0x2, 0x2, 0x2, 0x28, 0x4c, 
       0x4e, 0x55, 0x5e, 0x69, 0x6f, 0x73, 0x7c, 0x7f, 0x82, 0x8a, 0x93, 
       0x99, 0x9d, 0xaa, 0xad, 0xbb, 0xc1, 0xc8, 0xd0, 0xdf, 0xf0, 0xf3, 
       0xfb, 0x104, 0x10c, 0x112, 0x118, 0x121, 0x12d, 0x13b, 0x143, 0x14b, 
       0x159, 0x168, 0x175, 0x17a, 0x17f, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CACTParser::Initializer CACTParser::_init;
