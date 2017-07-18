#pragma once
#include"stdafx.h"

//this is the Interface for tokens objects (Operators, Punctuation and Keywords)
//we have 3 types of operators and white spaces {SELECT, *-=+ , !?; }

enum class TokenType
{
	KeywordType ,
	OperatorType,
	PunctuationType,
	WhiteSpaceType,
	IdentifierType,
	DigitType
};




// This is the Interface for tokens objects (Operators, Punctuation and Keywords)
class IToken
{
public:
	
	// This will return the type of the token
	virtual TokenType GetType() const  = 0;

	// This will return the string or character stored by each token
	virtual string GetWord() const = 0;

	// Destructor
	virtual ~IToken() {};

};

