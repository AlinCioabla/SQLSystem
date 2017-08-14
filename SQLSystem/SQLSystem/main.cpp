#include "stdafx.h"
#include "ITestUnit.h"
#include "Ast.h"
#include "AstNode.h"
#include "Lexer.h"
#include "LexerTestUnit.h"
#include "LexerTester.h"
#include "Parser.h"
#include "ParserTestUnit.h"
#include "SQLSystem.h"

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
  lexerTestUnit.CreateTest("TestFile11.txt"s);
  lexerTestUnit.CreateTest("TestFile12.txt"s);
  lexerTestUnit.CreateTest("TestFile13.txt"s);
  lexerTestUnit.CreateTest("TestFile14.txt"s);
  lexerTestUnit.CreateTest("TestFile15.txt"s);
  lexerTestUnit.ExecuteAllTests();
}

void TestParser()
{
  ParserTestUnit parserTestUnit;
  parserTestUnit.CreateTest("TestFile1.txt"s);
  parserTestUnit.CreateTest("TestFile2.txt"s);
  parserTestUnit.CreateTest("TestFile3.txt"s);
  parserTestUnit.CreateTest("TestFile4.txt"s);
  parserTestUnit.CreateTest("TestFile5.txt"s);
  parserTestUnit.CreateTest("TestFile6.txt"s);
  parserTestUnit.CreateTest("TestFile7.txt"s);
  parserTestUnit.CreateTest("TestFile8.txt"s);
  parserTestUnit.CreateTest("TestFile9.txt"s);
  parserTestUnit.CreateTest("TestFile10.txt"s);
  parserTestUnit.CreateTest("TestFile11.txt"s);
  parserTestUnit.CreateTest("TestFile12.txt"s);
  parserTestUnit.CreateTest("TestFile13.txt"s);
  parserTestUnit.CreateTest("TestFile14.txt"s);
  parserTestUnit.CreateTest("TestFile15.txt"s);
  parserTestUnit.ExecuteAllTests();
}

int main()
{
  {
    /* ifstream fin("TestFile4.txt");
     Lexer    lexer1;
     lexer1.ReadFromFile(fin);
     lexer1.Tokenize();
     Parser parser1(lexer1);
     parser1.Parse();*/
    TestLexer();
    TestParser();
  }

  cout << endl;

  return 0;
}
