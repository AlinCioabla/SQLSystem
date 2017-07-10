#pragma once
#include "IToken.h"
class Punctuation :
	public IToken
{
public:
	Punctuation(char aWord) : mWord(aWord) {};
	string GetWord() const override;
	TokenType GetType() const override;
	~Punctuation();
private:
	char mWord;
};

