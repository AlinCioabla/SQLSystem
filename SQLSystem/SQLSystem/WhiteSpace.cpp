#include "WhiteSpace.h"



void WhiteSpace::PrintWord()
{
	cout << word << " whitespace" << endl;
}



TokenType WhiteSpace::GetType()
{
	return TokenType::WhiteSpaceType;
}


WhiteSpace::~WhiteSpace()
{
}
