#pragma once
#include "stdafx.h"
#include "IState.h"
#include "Ast.h"
#include "AstNode.h"
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
  Parser(ITokensTraversal & mLexer);

  bool Parse();
  Ast  GetAst();

  ~Parser();

private:
  ParserState mCurrentState;
  void        TransitionTo(ParserState aState);
  Ast         mAst;

  IState *           mCurrentState;
  TokenPtr           currentToken;
  TokenPtr           prevToken;
  AstNodePtr         currentInstructionNode;
  ITokensTraversal & mLexer;
};
