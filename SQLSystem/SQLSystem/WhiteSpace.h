#pragma once
#include "IToken.h"
class WhiteSpace :
	public IToken
{
public:
public:
	WhiteSpace(char _word) : word(_word) {}

	void PrintWord() override;
	TokenType GetType() override;
	~WhiteSpace();
	char word;
	
};

