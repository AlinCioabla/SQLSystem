#include "stdafx.h"
#include "ITestUnit.h"
#include "Ast.h"
#include "AstNode.h"
#include "Helpers.h"
#include "Lexer.h"
#include "LexerTestUnit.h"
#include "LexerTester.h"
#include "Parser.h"
#include "ParserTestUnit.h"
#include "SQLSystem.h"

void TestParser()
{
  ParserTestUnit parserTestUnit;
  parserTestUnit.CreateTest("TestFile11.txt"s);  // 1
  parserTestUnit.CreateTest("TestFile12.txt"s);  // 2
  parserTestUnit.CreateTest("TestFile13.txt"s);  // 3
  parserTestUnit.CreateTest("TestFile14.txt"s);  // 4
  parserTestUnit.CreateTest("TestFile15.txt"s);  // 5
  parserTestUnit.CreateTest("TestFile16.txt"s);  // 6
  parserTestUnit.CreateTest("TestFile17.txt"s);  // 7
  parserTestUnit.CreateTest("TestFile18.txt"s);  // 8
  parserTestUnit.CreateTest("TestFile19.txt"s);  // 9
  parserTestUnit.CreateTest("TestFile20.txt"s);  // 10
  parserTestUnit.ExecuteAllTests();
}

void TestLexer()
{
  LexerTestUnit lexerTestUnit;
  lexerTestUnit.CreateTest("TestFile1.txt"s);
  lexerTestUnit.CreateTest("TestFile2.txt"s);
  lexerTestUnit.CreateTest("TestFile3.txt"s);
  lexerTestUnit.CreateTest("TestFile4.txt"s);
  lexerTestUnit.CreateTest("TestFile5.txt"s);
  lexerTestUnit.CreateTest("TestFile6.txt"s);
  lexerTestUnit.CreateTest("TestFile7.txt"s);
  lexerTestUnit.CreateTest("TestFile8.txt"s);
  lexerTestUnit.CreateTest("TestFile9.txt"s);
  lexerTestUnit.CreateTest("TestFile10.txt"s);

  lexerTestUnit.ExecuteAllTests();
}

int main()
{
  // TestLexer();
  TestParser();

  return 0;
}
