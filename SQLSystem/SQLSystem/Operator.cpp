#include "Operator.h"



void Operator::PrintWord()
{
	cout << word << "  operator"<<endl;
}



TokenType Operator::GetType()
{
	return TokenType::OperatorType;
}


Operator::~Operator()
{
}
