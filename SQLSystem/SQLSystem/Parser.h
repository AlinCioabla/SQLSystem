#pragma once
#include"Lexer.h"

class Parser
{
	Lexer m_lexer;

public:

	Parser(Lexer lexer) :m_lexer(lexer) {};

	~Parser();
};

