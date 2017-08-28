#pragma once
#include "stdafx.h"
#include "IState.h"
#include "Ast.h"
#include "AstNode.h"
#include "DiagnosticInfo.h"
#include "Lexer.h"
#include "Undefined.h"

class Parser
{
public:
  explicit Parser(ITokensTraversal & aLexer);

  // Parse the tokens provided by the Lexer
  DiagnosticInfo Parse();

  // Returns a reference to the resulted Ast
  Ast & GetAst();

  ~Parser();

private:
  Ast                mAst;
  unique_ptr<IState> mCurrentState;
  TokenPtr           mCurrentToken;
  ITokensTraversal & mLexer;
};
