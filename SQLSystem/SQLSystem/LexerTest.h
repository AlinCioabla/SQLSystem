#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include "Test.h"

// Class that test the functionality of a ITokensTraversal module
class LexerTest
{
public:
  LexerTest(string aFileName)
    : mInputFileName(aFileName)
    , mLexer(make_unique<Lexer>())
  {
  }

  bool Execute();

  ~LexerTest();

private:
  bool                         TestInputFile(ifstream & aInputFile);
  bool                         TestReadFromFile(ifstream & aInputFile);
  DiagnosticInfo               TestTokenize(ifstream & aInputFile);
  bool                         TestGetSqlCommand(ifstream & aInputFile);
  string                       mInputFileName;
  unique_ptr<ITokensTraversal> mLexer;
};
