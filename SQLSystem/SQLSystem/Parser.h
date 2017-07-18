#pragma once
#include"stdafx.h"
#include"Lexer.h"
#include"ICommand.h"
#include"Begin.h"
#include"Intermediar.h"
#include"Final.h"
#include"AstNode.h"
#include"Word.h"

enum ParserState
{
	SELECT,
	FROM,
	WHERE,
	LIKE,
	AND,
	UNDEFINED,
	INVALID
};

class Parser
{
public:

	Parser();
	
	bool Parse(ITokensTraversal* &aLexer);



	~Parser();
private:
	ParserState mCurrentState;
	void TransitionTo(ParserState aState);


};

