#pragma once
#include "IToken.h"
class Punctuation :
	public IToken
{
public:
	Punctuation(char _word) : word(_word) {};
	string GetWord() override;
	void PrintWord() override;
	TokenType GetType() override;
	~Punctuation();
private:
	char word;
};

