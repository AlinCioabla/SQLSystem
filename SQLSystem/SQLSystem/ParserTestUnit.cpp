#include "stdafx.h"
#include "ParserTestUnit.h"
#include "IPresenter.h"

void ParserTestUnit::ExecuteAllTests()
{
  for (auto & test : mTests)
  {
    DiagnosticInfo testDiagInfo = test->Execute();
    mPresenter.Present(test->GetNumber(), testDiagInfo);
  }
}

void ParserTestUnit::CreateTest(string aFileName)
{
  mTests.push_back(make_unique<ParserTest>(aFileName, mTests.size() + 1));
}

ParserTestUnit::~ParserTestUnit() = default;