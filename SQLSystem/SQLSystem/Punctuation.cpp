#include "Punctuation.h"





void Punctuation::PrintWord()
{
	cout << word << " ";
}

TokenType Punctuation::GetType()
{
	return TokenType::PunctuationType;
}


Punctuation::~Punctuation()
{
}
