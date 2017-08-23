#include "stdafx.h"
#include "LexerTestUnit.h"
#include "DiagnosticInfo.h"

void LexerTestUnit::ExecuteAllTests()
{
  for (auto & test : mTests)
  {
    DiagnosticInfo testDiagInfo = test->Execute();
    mPresenter.Present(test->GetNumber(), testDiagInfo);
  }
}

void LexerTestUnit::CreateTest(string aFileName)
{
  mTests.push_back(make_unique<LexerTest>(aFileName, mTests.size() + 1));
}

LexerTestUnit::~LexerTestUnit() = default;
