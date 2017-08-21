#pragma once
#include "stdafx.h"
#include "ITestUnit.h"
#include "ConsolePresenter.h"
#include "FilePresenter.h"
#include "Lexer.h"
#include "Parser.h"
#include "ParserTest.h"

class ParserTestUnit : public ITestUnit
{
public:
  ParserTestUnit(IPresenter & aPresenter)
    : mPresenter(aPresenter)
  {
  }

  void ExecuteAllTests() override;

  void CreateTest(string aFileName);

  ~ParserTestUnit();

private:
  vector<unique_ptr<ParserTest>> mTests;
  IPresenter &                   mPresenter;
};
