#include "stdafx.h"
#include "ParserTestUnit.h"

void ParserTestUnit::ExecuteAllTests()
{
  {
    int index = 1;
    for (auto & test : mTests)
    {
      cout << "-------------------------------------" << endl << endl;
      cout << "Parser Test: " << index << endl;
      bool succes = test.Execute(*mTokensTraversal[index - 1], mParser[index - 1]);
      cout << "Result: ";
      if (succes)
        cout << "Success!" << endl;
      else
        cout << "Failed" << endl;
      cout << "-------------------------------------" << endl;
      index++;
    }
  }
}

void ParserTestUnit::CreateTest(string                       aFileName,
                                Parser &                     aParser,
                                shared_ptr<ITokensTraversal> aTokenTravesral)
{
  ParserTest test(aFileName);
  mTests.push_back(test);
  mParser.push_back(aParser);
  mTokensTraversal.push_back(move(aTokenTravesral));
}

ParserTestUnit::~ParserTestUnit()
{
  mTests.clear();
}