#include "stdafx.h"
#include "TestUnit.h"
bool LexerTests()
{
  // Test #1
  cout << "Lexer Test1: " << endl;
  ifstream    _inputFile1("TestFile1.txt");
  Lexer       _lexer1;
  LexerTester lexerTester1(_inputFile1, _lexer1);
  bool        _succes1 = lexerTester1.TestTokens();
  cout << _succes1 << endl << endl;

  // Test #2
  cout << "Lexer Test2: " << endl;
  ifstream    _inputFile2("TestFile2FAKE.txt");
  Lexer       _lexer2;
  LexerTester lexerTester2(_inputFile2, _lexer2);
  bool        _succes2 = lexerTester2.TestTokens();
  cout << _succes2 << endl << endl;

  // Test #3
  cout << "Lexer Test3: " << endl;
  ifstream    _inputFile3("TestFile3.txt");
  Lexer       _lexer3;
  LexerTester lexerTester3(_inputFile3, _lexer3);
  bool        _succes3 = lexerTester3.TestTokens();
  cout << _succes3 << endl << endl;

  if (_succes1 && _succes2 && _succes3)
    return true;
  return false;
}

bool ParserTests()
{
  // Test1
  cout << "Parser Test1: " << endl;
  ifstream           _inputFile1("TestFile1.txt");
  ITokensTraversal * lexer1 = new Lexer();
  lexer1->ReadFromFile(_inputFile1);
  lexer1->Tokenize();
  Parser       parser1;
  ParserTester parserTester1(parser1, lexer1);

  bool succes1 = parserTester1.ConstructAst();
  if (!succes1)
  {
    cout << "Failed to construct AST. Invalid syntax." << endl;
  }
  else
  {
    parserTester1.DisplayAst();
    cout << endl << "Query from AST: " << endl;
    parserTester1.PrintQueryFromAst();
    cout << endl << endl << "Initial Query: " << endl;
    cout << lexer1->GetSqlCommand() << endl;
    cout << "////////////////////////////////////////////////////////" << endl;
  }

  // Test2
  cout << "Parser Test2: " << endl;
  ifstream           _inputFile2("TestFile2.txt");
  ITokensTraversal * lexer2 = new Lexer();
  lexer2->ReadFromFile(_inputFile2);
  lexer2->Tokenize();
  Parser       parser2;
  ParserTester parserTester2(parser2, lexer2);

  bool succes2 = parserTester2.ConstructAst();
  if (!succes2)
  {
    cout << "Failed to construct AST. Invalid syntax." << endl;
  }
  else
  {
    parserTester2.DisplayAst();
    cout << endl << "Query from AST: " << endl;
    parserTester2.PrintQueryFromAst();
    cout << endl << endl << "Initial Query: " << endl;
    cout << lexer2->GetSqlCommand() << endl;
    cout << "////////////////////////////////////////////////////////" << endl;
  }

  // Test3
  cout << "Parser Test3: " << endl;
  ifstream           _inputFile3("TestFile3.txt");
  ITokensTraversal * lexer3 = new Lexer();
  lexer3->ReadFromFile(_inputFile3);
  lexer3->Tokenize();
  Parser       parser3;
  ParserTester parserTester3(parser3, lexer3);

  bool succes3 = parserTester3.ConstructAst();
  if (!succes3)
  {
    cout << "Failed to construct AST. Invalid syntax." << endl;
  }
  else
  {
    parserTester3.DisplayAst();
    cout << endl << "Query from AST: " << endl;
    parserTester3.PrintQueryFromAst();
    cout << endl << endl << "Initial Query: " << endl;
    cout << lexer3->GetSqlCommand() << endl;
    cout << "////////////////////////////////////////////////////////" << endl;
  }

  if (succes1 && succes2 && succes3)
  {
    return true;
  }
  return false;
}
