#include "Keyword.h"



void Keyword::PrintWord()
{
	cout << word << " "<<"keyword"<<endl;
}

TokenType Keyword::GetType()
{
	return TokenType::KeywordType;
}

string Keyword::GetWord()
{
	return word;
}


Keyword::~Keyword()
{
}
