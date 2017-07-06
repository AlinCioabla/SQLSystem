#pragma once
#include "IToken.h"
class Operator :
	public IToken
{
public:
	Operator(char _word) : word(_word) {};
	char GetWord() { return word; }
	void PrintWord() override;
	TokenType GetType() override;
	~Operator();
private:
	char word;
};

