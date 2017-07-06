#pragma once
#include "IToken.h"
class Punctuation :
	public IToken
{
public:
	Punctuation(char _word) : word(_word) {};
	TokenType GetType() override;
	~Punctuation();
private:
	char word;
};

