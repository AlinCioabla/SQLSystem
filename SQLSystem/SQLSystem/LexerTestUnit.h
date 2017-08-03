#pragma once

#include "stdafx.h"
#include "ITestUnit.h"
#include "Lexer.h"
#include "LexerTest.h"
#include "LexerTestUnit.h"
#include "Test.h"

class LexerTestUnit : public ITestUnit
{
public:
  LexerTestUnit(Lexer & aLexer);

  void ExecuteAllTests() override;

  void CreateTest(string aFileName) override;

  ~LexerTestUnit();

private:
  Lexer &           mLexer;
  vector<LexerTest> mTests;
};
