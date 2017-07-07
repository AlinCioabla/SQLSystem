#pragma once
#include "IToken.h"
class Keyword :
	public IToken
{
public:
	Keyword(string _word) : word(_word) {}

	void PrintWord() override;
	TokenType GetType() override;
	string GetWord() override;
	~Keyword();
private:
	string word;
};

