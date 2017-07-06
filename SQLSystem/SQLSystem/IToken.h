#pragma once
#include"stdafx.h"

enum TokenType
{
	KeywordType = 0,
	OperatorType,
	PunctuationType
};


class IToken
{
public:
	virtual TokenType GetType() = 0;
	virtual ~IToken() {};

};

