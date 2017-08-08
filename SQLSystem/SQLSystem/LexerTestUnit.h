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
  LexerTestUnit(){};

  void ExecuteAllTests() override;

  void CreateTest(string aFileName);

  ~LexerTestUnit();

private:
  vector<unique_ptr<LexerTest>> mTests;
};
