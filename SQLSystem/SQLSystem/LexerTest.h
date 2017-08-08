#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include "Test.h"

class LexerTest
{
public:
  LexerTest(string aFileName)
    : mInputFileName(aFileName)
  {
    mLexer = new Lexer();
  }

  bool Execute();

  ~LexerTest();

private:
  bool               TestInputFile(ifstream & aInputFile);
  bool               TestReadFromFile(ifstream & aInputFile);
  bool               TestTokenize(ifstream & aInputFile);
  bool               TestGetSqlCommand(ifstream & aInputFile);
  string             mInputFileName;
  ITokensTraversal * mLexer;
};
