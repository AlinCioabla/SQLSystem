#pragma once
#include "IToken.h"

//This class is for string like :{ ".,?""'&!;:_()" };
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

