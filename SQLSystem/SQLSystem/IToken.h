#pragma once
#include"stdafx.h"

enum TokenType
{
	Keyword = 0,
	Operator,
	Punctuation
};


class IToken
{
public:
	IToken();
	



	virtual TokenType GetType() = 0;
	virtual ~IToken();

};

