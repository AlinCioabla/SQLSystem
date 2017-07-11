#include "Punctuation.h"





string Punctuation::GetWord()const
{
	string s_word;
	s_word += mWord;
	return s_word;
}


TokenType Punctuation::GetType()const
{
	return TokenType::PunctuationType;
}


Punctuation::~Punctuation()
{
}
