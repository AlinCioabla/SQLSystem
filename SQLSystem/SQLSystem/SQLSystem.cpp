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
	lexer.SetTokens(lexer.ReadFile(in));


}


SQLSystem::~SQLSystem()
{
}
