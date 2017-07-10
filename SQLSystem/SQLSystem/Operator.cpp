#include "Operator.h"



string Operator::GetWord()
{
	string s_word;
	s_word+= word;
	return s_word;
}

TokenType Operator::GetType()
{
	return TokenType::OperatorType;
}


Operator::~Operator()
{
}
