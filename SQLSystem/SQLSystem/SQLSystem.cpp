#include "SQLSystem.h"
#include"Lexer.h"
#include"Parser.h"
#include"LexerTester.h"


SQLSystem::SQLSystem()
{
}

void SQLSystem::Start(ifstream & in)
{
	Lexer lexer;
	Parser parser(lexer.tokens);
	lexer.ReadFromFile(in);
	lexer.SetTokens();
	//lexer.PrintTokenTypes();
	LexerTester tester(lexer);
	bool testResult = tester.TestTokens();
	cout << "Token test: " << testResult << endl;
	for (auto it : parser.GetKeywords())
		cout << it << endl;



}


SQLSystem::~SQLSystem()
{
}
