#pragma once
#include "stdafx.h"
#include "ICommand.h"
#include "AstNode.h"
#include "Begin.h"
#include "Final.h"
#include "Intermediar.h"
#include "Lexer.h"

enum ParserState
{
  SELECT,
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

  bool Parse(ITokensTraversal *& aLexer);

  ~Parser();

private:
  ParserState mCurrentState;
  void        TransitionTo(ParserState aState);
};
