#include "SQLSystem.h"
#include"Lexer.h"
#include"Parser.h"


SQLSystem::SQLSystem()
{
}

void SQLSystem::Start(ifstream & in)
{
	Lexer lexer;
	Parser parsser;
	lexer.ReadFromFile(in);
	lexer.SetTokens();
	lexer.PrintTokens();


}


SQLSystem::~SQLSystem()
{
}
