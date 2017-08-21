#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include "Test.h"

// Class that test the functionality of a ITokensTraversal module
class LexerTest
{
public:
  LexerTest(string aFileName, size_t aTestNumber)
    : mInputFileName(aFileName)
    , mLexer(make_unique<Lexer>())
    , mTestNumber(aTestNumber)
  {
  }
  DiagnosticInfo Execute();

  int GetNumber() const { return mTestNumber; };

  ~LexerTest();

private:
  string                       mInputFileName;
  unique_ptr<ITokensTraversal> mLexer;
  size_t                       mTestNumber;
  bool                         TestInputFile(ifstream & aInputFile);
  bool                         TestReadFromFile(ifstream & aInputFile);
  DiagnosticInfo               TestTokenize(ifstream & aInputFile);
  bool                         TestGetSqlCommand(ifstream & aInputFile);
};
