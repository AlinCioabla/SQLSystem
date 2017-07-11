#pragma once
#include"stdafx.h"

//this is the Interface for tokens objects (Operators, Punctuation and Keywords)
//we have 3 types of operators and white spaces {SELECT, *-=+ , !?; }

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
	virtual string GetWord() const = 0;//gets the word inside an object  as a string 
	virtual ~IToken() {};

};

