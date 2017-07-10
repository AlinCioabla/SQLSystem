#include "Keyword.h"





TokenType Keyword::GetType()const
{
	return TokenType::KeywordType;
}

string Keyword::GetWord()const
{
	return mWord;
}


Keyword::~Keyword()
{
}
