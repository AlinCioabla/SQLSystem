#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include "Parser.h"

// A class used to test the functionality of the Parser
class ParserTest
{
public:
  ParserTest(string aFileName)
    : mInputFileName(aFileName)
  {
    mLexer  = new Lexer();
    mParser = new Parser(*mLexer);
  }

  bool Execute();

  ~ParserTest();

private:
  bool               TestInputFile(ifstream & aInputFile);
  bool               TestConstructAst();
  bool               TestAst();
  void               PrintQueryFromAst();
  void               DisplayAst();
  string             mInputFileName;
  Parser *           mParser;
  ITokensTraversal * mLexer;
};
