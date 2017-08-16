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

  ~ParserTester();

private:
  DiagnosticInfo     ConstructAst();
  void               PrintQueryFromAst();
  void               DisplayAst();
  bool               TestAst();
  Parser &           mParser;
  ITokensTraversal & mLexer;
};
