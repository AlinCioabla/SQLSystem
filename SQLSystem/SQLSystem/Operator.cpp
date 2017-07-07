#include "Operator.h"



string Operator::GetWord()
{
	string s_word;
	s_word+= word;
	return s_word;
}

void Operator::PrintWord()
{
	cout << word <<" operator"<<endl;
}



TokenType Operator::GetType()
{
	return TokenType::OperatorType;
}


Operator::~Operator()
{
}
