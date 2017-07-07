#include "WhiteSpace.h"



void WhiteSpace::PrintWord()
{
	cout << word << " " << endl;
}



TokenType WhiteSpace::GetType()
{
	return TokenType::OperatorType;
}


WhiteSpace::~WhiteSpace()
{
}
