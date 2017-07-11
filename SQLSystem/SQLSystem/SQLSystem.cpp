#include "SQLSystem.h"
#include"Lexer.h"
#include"Parser.h"
#include"LexerTester.h"
ifstream instr("Instr.txt");

SQLSystem::SQLSystem()
{
}

void SQLSystem::Start(ifstream & in)
{
	
	Lexer lexer;
	Parser parser(lexer.mTokens);
	//lexer.ReadFromFile(in);
	//lexer.Tokenize();
	////lexer.PrintTokenTypes();
	//LexerTester tester(lexer);
	//bool testResult = tester.TestTokens();
	//parser.SetKeywords(instr);
	//cout << "Token test: " << testResult << endl;
	//for (auto it : parser.GetKeywords())
	//	cout << it << endl;



}


SQLSystem::~SQLSystem()
{
}
