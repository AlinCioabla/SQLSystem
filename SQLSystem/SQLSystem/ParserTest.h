#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include "Parser.h"

// A class used to test the functionality of the Parser
class ParserTest
{
public:
  ParserTest(string aFileName, size_t aTestNumber)
    : mInputFileName(aFileName)
    , mLexer(make_unique<Lexer>())
    , mParser(make_unique<Parser>(*mLexer))
    , mTestNumber(aTestNumber)

  {
  }

  DiagnosticInfo Execute();

  int GetNumber() const { return mTestNumber; };

  ~ParserTest();

private:
  bool                         TestInputFile(ifstream & aInputFile);
  DiagnosticInfo               TestConstructAst();
  bool                         TestAst();
  void                         PrintQueryFromAst();
  void                         DisplayAst();
  string                       mInputFileName;
  unique_ptr<ITokensTraversal> mLexer;
  unique_ptr<Parser>           mParser;
  int                          mTestNumber;
};
