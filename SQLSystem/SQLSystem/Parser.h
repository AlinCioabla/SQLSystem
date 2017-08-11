#pragma once
#include "stdafx.h"
#include "IState.h"
#include "Ast.h"
#include "AstNode.h"
#include "Lexer.h"
#include "Undefined.h"

class Parser
{
public:
  Parser(ITokensTraversal & mLexer);

  // Parse the tokens provided by the Lexer
  bool Parse();

  // Returns a reference to the resulted Ast
  Ast & GetAst();

  ~Parser();

private:
  Ast mAst;

  unique_ptr<IState> mCurrentState;
  TokenPtr           mCurrentToken;
  IToken *           mPrevToken;
  AstNodePtr         mCurrentInstructionNode;
  ITokensTraversal & mLexer;
};
