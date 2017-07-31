#pragma once
#include "stdafx.h"
#include "ITokensTraversal.h"
#include "Parser.h"

class ParserTester
{
public:
  ParserTester(unique_ptr<Parser> & aParser, unique_ptr<ITokensTraversal> & aLexer)
    : mParser(move(aParser))
    , mLexer(move(aLexer))
  {
  }

  bool ConstructAst();
  void PrintQueryFromAst();
  void DisplayAst();
  bool TestAst();

  ~ParserTester();

private:
  unique_ptr<Parser>           mParser;
  unique_ptr<ITokensTraversal> mLexer;
};
