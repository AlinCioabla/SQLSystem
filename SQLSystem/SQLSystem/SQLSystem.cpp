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
	Parser parsser;
	lexer.ReadFromFile(in);
	lexer.SetTokens();
	//lexer.PrintTokenTypes();
	LexerTester tester(lexer);
	cout << tester.TestTokens();


}


SQLSystem::~SQLSystem()
{
}
