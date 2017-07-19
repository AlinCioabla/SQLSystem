#include "Parser.h"
#include"Ast.h"




Parser::Parser()
{

}

bool Parser::Parse(ITokensTraversal * &aLexer)
{

	mCurrentState = UNDEFINED;
	IToken *currentToken = aLexer->GetNextToken();

	while(currentToken != nullptr)
	{
		


	}


	return false;
}



Parser::~Parser()
{
}

void Parser::TransitionTo(ParserState aState)
{
	mCurrentState = aState;
}
