#include "SQLSystem.h"
#include "Lexer.h"
#include "LexerTester.h"
#include "Parser.h"
ifstream instr("Instr.txt");

SQLSystem::SQLSystem() = default;

void SQLSystem::Start(ifstream &instr) {

  // Lexer lexer;
  // Parser parser(lexer.mTokens);
  // parser.SetCommands();
  // lexer.ReadFromFile(in);
  // lexer.Tokenize();
  // lexer.PrintTokenTypes();
  // LexerTester tester(lexer);
  // bool testResult = tester.TestTokens();
  // parser.SetKeywords(instr);
  // cout << "Token test: " << testResult << endl;
  // for (auto it : parser.GetKeywords())
  //	cout << it << endl;
}

SQLSystem::~SQLSystem() = default;
