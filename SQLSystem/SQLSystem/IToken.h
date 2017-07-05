#pragma once
#include"stdafx.h"

enum TokenType
{
	Keyword,
	Operator,
	Punctuation
};


class IToken
{
public:
	IToken();
	



	virtual TokenType GetType() = 0;

	virtual ~IToken();
private:
	string word;
};

