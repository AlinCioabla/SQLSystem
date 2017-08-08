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

  void CreateTest(string aFileName, Parser & aParser, shared_ptr<ITokensTraversal> aTokenTravesral);

  ~ParserTestUnit();

private:
  vector<Parser>     mParser;
  vector<TravPtr>    mTokensTraversal;
  vector<ParserTest> mTests;
};
