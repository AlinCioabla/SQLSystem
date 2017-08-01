#include "stdafx.h"
#include "LexerTestUnit.h"

LexerTestUnit::LexerTestUnit(Lexer & aLexer)
  : mLexer(aLexer)

{
}

void LexerTestUnit::ExecuteAllTests()
{
  int index = 1;
  for (auto & test : mTests)
  {
    cout << "-------------------------------------" << endl << endl;
    cout << "Lexer Test: " << index++ << endl;
    bool succes = test.Execute(mLexer);
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
  LexerTest test(aFileName);
  mTests.push_back(test);
}

LexerTestUnit::~LexerTestUnit()
{
  mTests.clear();
}
