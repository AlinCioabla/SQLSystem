#pragma once
#include "stdafx.h"
#include "Lexer.h"
#include"IToken.h"

class LexerTester
{
	Lexer mLexer;
	ifstream &mIn;

public:
	LexerTester(ifstream &aIn, Lexer &aLexer) : mLexer(aLexer), mIn(aIn) {}

	//Tests Tokennize function and ReadFromFile
	bool TestTokens();
	~LexerTester();
};

