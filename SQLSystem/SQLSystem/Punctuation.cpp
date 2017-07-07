#include "Punctuation.h"





string Punctuation::GetWord()
{
	string s_word;
	s_word += word;
	return s_word;
}

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
