#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include "Parser.h"

class ParserTest
{
public:
  ParserTest(string aFileName)
    : mInputFileName(aFileName)
  {
  }

  bool Execute(ITokensTraversal & aLexer, Parser & aParser);

  ~ParserTest();

private:
  bool   TestInputFile(ifstream & aInputFile);
  bool   TestConstructAst(ITokensTraversal & aLexer, Parser & aParser);
  bool   TestAst(Parser aParser);
  void   PrintQueryFromAst(Parser aParser);
  void   DisplayAst(Parser aParser);
  string mInputFileName;
};
