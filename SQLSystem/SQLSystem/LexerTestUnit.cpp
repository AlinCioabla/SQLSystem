#include "stdafx.h"
#include "LexerTestUnit.h"

void LexerTestUnit::ExecuteAllTests()
{
  int index = 1;
  for (auto & test : mTests)
  {
    cout << "-------------------------------------" << endl << endl;
    cout << "Lexer Test: " << index++ << endl;
    bool succes = test->Execute();
    cout << "Result: ";
    if (succes)
      cout << "Success!" << endl;
    else
      cout << "Failed" << endl;
    cout << "-------------------------------------" << endl;
  }
}

void LexerTestUnit::CreateTest(string aFileName)
{
  mTests.push_back(make_unique<LexerTest>(aFileName));
}

LexerTestUnit::~LexerTestUnit()
{
}
