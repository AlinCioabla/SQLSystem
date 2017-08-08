#pragma once
#include "stdafx.h"
#include "IState.h"
#include "Ast.h"
#include "AstNode.h"
#include "Lexer.h"

class Parser
{
public:
  Parser(ITokensTraversal & mLexer);

  bool  Parse();
  Ast & GetAst();

  ~Parser();

private:
  Ast mAst;

  IState *           mCurrentState;
  TokenPtr           mCurrentToken;
  TokenPtr           mPrevToken;
  AstNodePtr         mCurrentInstructionNode;
  ITokensTraversal & mLexer;
};
