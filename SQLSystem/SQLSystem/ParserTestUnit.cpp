#include "stdafx.h"
#include "ParserTestUnit.h"

ParserTestUnit::~ParserTestUnit()
{
}

ParserTestUnit::ParserTestUnit(Parser & aParser, ITokensTraversal & aTokensTraversal)
  : mParser(aParser)
  , mTokensTraversal(aTokensTraversal)
{
}

void ParserTestUnit::ExecuteAllTests()
{
  {
    int index = 1;
    for (auto & test : mTests)
    {
      cout << "-------------------------------------" << endl << endl;
      cout << "Parser Test: " << index++ << endl;
      bool succes = test.Execute(mTokensTraversal, mParser);
      cout << "Result: ";
      if (succes)
        cout << "Success!" << endl;
      else
        cout << "Failed" << endl;
      cout << "-------------------------------------" << endl;
    }
  }
}

void ParserTestUnit::CreateTest(string aFileName)
{
  ParserTest test(aFileName);
  mTests.push_back(test);
}
