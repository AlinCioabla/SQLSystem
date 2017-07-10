#pragma once
#include "IToken.h"
class Operator :
	public IToken
{
public:
	Operator(char aWord) : mWord(aWord) {};
	string GetWord() const override;
	TokenType GetType() const override;
	~Operator();
private:
	char mWord;
};

