#include "WhiteSpace.h"



void WhiteSpace::PrintWord()
{
	cout << word << " whitespace" << endl;
}



TokenType WhiteSpace::GetType()
{
	return TokenType::WhiteSpaceType;
}

string WhiteSpace::GetWord()
{
	string s_word;
	s_word += word;
	return s_word;
}


WhiteSpace::~WhiteSpace()
{
}
