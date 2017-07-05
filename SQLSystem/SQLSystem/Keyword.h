#pragma once
#include "IToken.h"
class Keyword :
	public IToken
{
public:
	Keyword(string _word) : word(_word) {}
	TokenType GetType() override;
	~Keyword();
private:
	string word;
};

