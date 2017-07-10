#pragma once
#include"stdafx.h"

enum TokenType
{
	KeywordType ,
	OperatorType,
	PunctuationType,
	WhiteSpaceType
};


class IToken
{
public:
	
	virtual TokenType GetType() const  = 0;
	virtual string GetWord() const = 0;
	virtual ~IToken() {};

};

