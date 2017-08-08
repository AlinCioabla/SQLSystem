#include "stdafx.h"
#include "LexerTestUnit.h"

Lexer mLexer;
void  LexerTestUnit::ExecuteAllTests()
{
  int index = 1;
  for (auto & test : mTests)
  {
    cout << "-------------------------------------" << endl << endl;
    cout << "Lexer Test: " << index++ << endl;
    bool succes = test.Execute(mLexer[index - 2]);
    cout << "Result: ";
    if (succes)
      cout << "Success!" << endl;
    else
      cout << "Failed" << endl;
    cout << "-------------------------------------" << endl;
  }
}

void LexerTestUnit::CreateTest(string aFileName, Lexer & aLexer)
{
  LexerTest test(aFileName);
  mLexer.push_back(aLexer);
  mTests.push_back(test);
}

LexerTestUnit::~LexerTestUnit()
{
  mTests.clear();
}
