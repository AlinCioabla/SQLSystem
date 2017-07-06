#include "Operator.h"



void Operator::PrintWord()
{
	cout << word << " ";
}

TokenType Operator::GetType()
{
	return TokenType::OperatorType;
}


Operator::~Operator()
{
}
