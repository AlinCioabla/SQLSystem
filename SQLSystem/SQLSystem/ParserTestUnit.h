#pragma once
#include "stdafx.h"
#include "ITestUnit.h"
#include "Lexer.h"
#include "Parser.h"
#include "ParserTest.h"

class ParserTestUnit : public ITestUnit
{
public:
  ParserTestUnit(){};

  void ExecuteAllTests() override;

  void CreateTest(string aFileName);

  ~ParserTestUnit();

private:
  vector<unique_ptr<ParserTest>> mTests;
};
