#pragma once
#include "IToken.h"
class WhiteSpace :
	public IToken
{

public:
	WhiteSpace(char aWord) : mWord(aWord) {}

	TokenType GetType() const override;
	string GetWord() const override;
	~WhiteSpace();
	char mWord;
	
};

