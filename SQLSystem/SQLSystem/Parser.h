#pragma once
#include "stdafx.h"
#include "ICommand.h"
#include "Ast.h"
#include "AstNode.h"
#include "Begin.h"
#include "Final.h"
#include "Intermediar.h"
#include "Lexer.h"

enum ParserState
{
  SELECT,
  DELETE,
  UPDATE,
  DISTINCT,
  FROM,
  WHERE,
  INVALID,
  VALID,
  UNDEFINED
};

class Parser
{
public:
  Parser();

  bool  Parse(ITokensTraversal *& aLexer);
  Ast & GetAst();

  ~Parser();

private:
  ParserState mCurrentState;
  void        TransitionTo(ParserState aState);
  Ast         mAst;
};
