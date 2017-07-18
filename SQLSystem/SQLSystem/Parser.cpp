#include "Parser.h"
#include"Ast.h"




Parser::Parser()
{

}

bool Parser::Parse(ITokensTraversal * &aLexer)
{

	IToken* currentToken = aLexer->GetNextToken();
	IToken* anotherToken = aLexer->GetNextToken();


	return false;
}



Parser::~Parser()
{
}

void Parser::TransitionTo(ParserState aState)
{
	mCurrentState = aState;
}
