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
#include "TestUnit.h"

int main()
{
  auto lexer1  = make_shared<Lexer>();
  auto lexer2  = make_shared<Lexer>();
  auto lexer3  = make_shared<Lexer>();
  auto lexer4  = make_shared<Lexer>();
  auto lexer5  = make_shared<Lexer>();
  auto lexer6  = make_shared<Lexer>();
  auto lexer7  = make_shared<Lexer>();
  auto lexer8  = make_shared<Lexer>();
  auto lexer9  = make_shared<Lexer>();
  auto lexer10 = make_shared<Lexer>();
  auto lexer11 = make_shared<Lexer>();
  auto lexer12 = make_shared<Lexer>();
  auto lexer13 = make_shared<Lexer>();
  auto lexer14 = make_shared<Lexer>();
  auto lexer15 = make_shared<Lexer>();

  LexerTestUnit lexerTestUnit;
  lexerTestUnit.CreateTest("TestFile1.txt"s, *lexer1);
  lexerTestUnit.CreateTest("TestFile2.txt"s, *lexer2);
  lexerTestUnit.CreateTest("TestFile3.txt"s, *lexer3);
  lexerTestUnit.CreateTest("TestFile4.txt"s, *lexer4);
  lexerTestUnit.CreateTest("TestFile5.txt"s, *lexer5);
  lexerTestUnit.CreateTest("TestFile6.txt"s, *lexer6);
  lexerTestUnit.CreateTest("TestFile7.txt"s, *lexer7);
  lexerTestUnit.CreateTest("TestFile8.txt"s, *lexer8);
  lexerTestUnit.CreateTest("TestFile9.txt"s, *lexer9);
  lexerTestUnit.CreateTest("TestFile10.txt"s, *lexer10);
  lexerTestUnit.CreateTest("TestFile11.txt"s, *lexer11);
  lexerTestUnit.CreateTest("TestFile12.txt"s, *lexer12);
  lexerTestUnit.CreateTest("TestFile13.txt"s, *lexer13);
  lexerTestUnit.CreateTest("TestFile14.txt"s, *lexer14);
  lexerTestUnit.CreateTest("TestFile15.txt"s, *lexer15);
  lexerTestUnit.ExecuteAllTests();

  Parser parser1, parser2, parser3, parser4, parser5, parser6, parser7, parser8, parser9, parser10,
    parser11, parser12, parser13, parser14, parser15;

  ParserTestUnit parserTestUnit;
  parserTestUnit.CreateTest("TestFile1.txt"s, parser1, lexer1);
  parserTestUnit.CreateTest("TestFile2.txt"s, parser2, lexer2);
  parserTestUnit.CreateTest("TestFile3.txt"s, parser3, lexer3);
  parserTestUnit.CreateTest("TestFile4.txt"s, parser4, lexer4);
  parserTestUnit.CreateTest("TestFile5.txt"s, parser5, lexer5);
  parserTestUnit.CreateTest("TestFile6.txt"s, parser6, lexer6);
  parserTestUnit.CreateTest("TestFile7.txt"s, parser7, lexer7);
  parserTestUnit.CreateTest("TestFile8.txt"s, parser8, lexer8);
  parserTestUnit.CreateTest("TestFile9.txt"s, parser9, lexer9);
  parserTestUnit.CreateTest("TestFile10.txt"s, parser10, lexer10);
  parserTestUnit.CreateTest("TestFile11.txt"s, parser11, lexer11);
  parserTestUnit.CreateTest("TestFile12.txt"s, parser12, lexer12);
  parserTestUnit.CreateTest("TestFile13.txt"s, parser13, lexer13);
  parserTestUnit.CreateTest("TestFile14.txt"s, parser14, lexer14);
  parserTestUnit.CreateTest("TestFile15.txt"s, parser15, lexer15);
  parserTestUnit.ExecuteAllTests();

  return 0;
}
