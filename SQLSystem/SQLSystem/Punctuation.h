#pragma once
#include "IToken.h"
class Punctuation :
	public IToken
{
public:
	Punctuation(char _word) : word(_word) {};
	char GetWord() { return word; }
	void PrintWord() override;
	TokenType GetType() override;
	~Punctuation();
private:
	char word;
};

