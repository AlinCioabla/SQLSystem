#pragma once
#include "stdafx.h"
#include "ITokensTraversal.h"
#include "Parser.h"

class ParserTester
{
public:
  ParserTester(Parser & aParser, ITokensTraversal & aLexer)
    : mParser(aParser)
    , mLexer(aLexer)
  {
  }

  bool ConstructAst();
  void PrintQueryFromAst();
  void DisplayAst();
  bool TestAst();

  ~ParserTester();

private:
  Parser &           mParser;
  ITokensTraversal & mLexer;
};
