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
  }

  bool Execute(Lexer aLexer);

  ~LexerTest();

private:
  bool   TestInputFile(ifstream & aInputFile);
  bool   TestReadFromFile(Lexer & aLexer, ifstream & aInputFile);
  bool   TestTokenize(Lexer & aLexer);
  bool   TestGetNextToken(Lexer & aLexer);
  bool   TestGetSqlCommand(Lexer & aLexer);
  string mInputFileName;
};
