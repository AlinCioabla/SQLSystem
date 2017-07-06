#pragma once
#include "IToken.h"
class Operator :
	public IToken
{
public:
	Operator(char _word) : word(_word) {};
	TokenType GetType() override;
	~Operator();
private:
	char word;
};

