#pragma once
#include "AstNode.h"
#include "Begin.h"
#include "Final.h"
#include "ICommand.h"
#include "Intermediar.h"
#include "Lexer.h"
#include "stdafx.h"

enum ParserState { SELECT, FROM, WHERE, LIKE, AND, UNDEFINED, INVALID, VALID };

class Parser {
public:
  Parser();

  bool Parse(ITokensTraversal *&aLexer);

  ~Parser();

private:
  ParserState mCurrentState;
  void TransitionTo(ParserState aState);
};
