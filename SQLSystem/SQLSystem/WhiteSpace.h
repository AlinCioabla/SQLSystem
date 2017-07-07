#pragma once
#include "IToken.h"
class WhiteSpace :
	public IToken
{
public:
public:
	WhiteSpace(string _word) : word(_word) {}

	void PrintWord() override;
	TokenType GetType() override;
	~WhiteSpace();
	string word;
	
};

