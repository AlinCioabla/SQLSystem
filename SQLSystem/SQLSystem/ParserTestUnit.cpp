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
      bool succes = test->Execute();
      cout << endl << "Result: ";
      if (succes)
      {
        cout << "Success!" << endl;
      }
      else
      {
        cout << "Failed" << endl;
      }
      cout << "-------------------------------------" << endl;
      index++;
    }
  }
}

void ParserTestUnit::CreateTest(string aFileName)
{
  mTests.push_back(make_unique<ParserTest>(aFileName));
}

ParserTestUnit::~ParserTestUnit() = default;