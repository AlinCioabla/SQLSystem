#pragma once
#include "IToken.h"
class WhiteSpace :
	public IToken
{

public:
	WhiteSpace(char _word) : word(_word) {}

	void PrintWord() override;
	TokenType GetType() override;
	string GetWord() override;
	~WhiteSpace();
	char word;
	
};

