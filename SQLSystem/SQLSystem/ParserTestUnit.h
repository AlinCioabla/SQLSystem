#pragma once
#include "stdafx.h"
#include "ITestUnit.h"
#include "Lexer.h"
#include "Parser.h"
#include "ParserTest.h"

class ParserTestUnit : public ITestUnit
{
public:
  ParserTestUnit(Parser & aParser, ITokensTraversal & aTokensTraversal);

  void ExecuteAllTests() override;

  void CreateTest(string aFileName) override;

  ~ParserTestUnit();

private:
  Parser &           mParser;
  ITokensTraversal & mTokensTraversal;
  vector<ParserTest> mTests;
};
