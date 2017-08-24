#include "stdafx.h"
#include "ConsolePresenter.h"
#include "FilePresenter.h"
#include "Helpers.h"
#include "LexerTestUnit.h"
#include "ParserTestUnit.h"
#include "SQLSystem.h"
void TestLexer()
{
  // Create the test unit for the lexer
  ConsolePresenter consolePresenter;

  LexerTestUnit lexerTestUnit(consolePresenter);

  // Create tests by giving the filename for the input
  lexerTestUnit.CreateTest("TestFile1.txt"s);   // 1
  lexerTestUnit.CreateTest("TestFile2.txt"s);   // 2
  lexerTestUnit.CreateTest("TestFile3.txt"s);   // 3
  lexerTestUnit.CreateTest("TestFile4.txt"s);   // 4
  lexerTestUnit.CreateTest("TestFile5.txt"s);   // 5
  lexerTestUnit.CreateTest("TestFile6.txt"s);   // 6 - supposed to fail
  lexerTestUnit.CreateTest("TestFile7.txt"s);   // 7 - supposed to fail
  lexerTestUnit.CreateTest("TestFile8.txt"s);   // 8 - supposed to fail
  lexerTestUnit.CreateTest("TestFile9.txt"s);   // 9 - supposed to fail
  lexerTestUnit.CreateTest("TestFile10.txt"s);  // 10 - supposed to fail

  // Execute the tests
  lexerTestUnit.ExecuteAllTests();
}

void TestParser()
{
  // Create the test unit for the parser
  ConsolePresenter consolePresenter;
  ParserTestUnit   parserTestUnit(consolePresenter);

  // Create tests by giving the filename for the input
  parserTestUnit.CreateTest("TestFile11.txt"s);  // 1
  parserTestUnit.CreateTest("TestFile12.txt"s);  // 2
  parserTestUnit.CreateTest("TestFile13.txt"s);  // 3
  parserTestUnit.CreateTest("TestFile14.txt"s);  // 4
  parserTestUnit.CreateTest("TestFile15.txt"s);  // 5
  parserTestUnit.CreateTest("TestFile16.txt"s);  // 6 - supposed to fail
  parserTestUnit.CreateTest("TestFile17.txt"s);  // 7 - supposed to fail
  parserTestUnit.CreateTest("TestFile18.txt"s);  // 8 - supposed to fail
  parserTestUnit.CreateTest("TestFile19.txt"s);  // 9 - supposed to fail
  parserTestUnit.CreateTest("TestFile20.txt"s);  // 10 - supposed to fail

  // Execute the tests
  parserTestUnit.ExecuteAllTests();
}

int main()
{
  {
    // TestLexer();
    TestParser();
  }
  return 0;
}
