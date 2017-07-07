#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include"IToken.h"

class LexerTester
{
	Lexer m_lexer;

public:
	LexerTester(Lexer lexer):m_lexer(lexer) {};
	bool TestTokens();
	~LexerTester();
};

