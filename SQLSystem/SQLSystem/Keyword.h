#pragma once
#include "IToken.h"
class Keyword :
	public IToken
{
public:
	Keyword(string aWord) : mWord(aWord) {}

	
	TokenType GetType() const override;
	string GetWord() const override;
	~Keyword();
private:
	string mWord;
};

