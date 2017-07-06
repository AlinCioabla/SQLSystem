#include "Keyword.h"



void Keyword::PrintWord()
{
	cout << word << " ";
}

TokenType Keyword::GetType()
{
	return TokenType::KeywordType;
}


Keyword::~Keyword()
{
}
