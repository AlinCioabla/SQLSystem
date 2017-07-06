#include "Punctuation.h"





void Punctuation::PrintWord()
{
	cout << word << " punctuation" << endl;
}

TokenType Punctuation::GetType()
{
	return TokenType::PunctuationType;
}


Punctuation::~Punctuation()
{
}
