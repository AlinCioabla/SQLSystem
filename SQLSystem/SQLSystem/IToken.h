#pragma once
#include"stdafx.h"

enum TokenType
{
	KeywordType ,
	OperatorType,
	PunctuationType,
	WhiteSpace
};


class IToken
{
public:
	virtual void PrintWord() = 0;
	virtual TokenType GetType() = 0;
	virtual ~IToken() {};

};

