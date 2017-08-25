#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include "Parser.h"
#include "TextRewriter.h"

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

  size_t GetNumber() const { return mTestNumber; };

  ~ParserTest();

private:
  bool           TestInputFile(ifstream & aInputFile);
  bool           TestAst();
  DiagnosticInfo TestConstructAst();

  string                       mInputFileName;
  unique_ptr<ITokensTraversal> mLexer;
  unique_ptr<Parser>           mParser;
  size_t                       mTestNumber;
};
