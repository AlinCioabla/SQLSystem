#include"stdafx.h"
#include "Lexer.h"



Lexer::Lexer()
{
}

void Lexer::ReadFromFile(ifstream & in)
{
	char c;
	string sqlCommand;
	while (in >> c && c != ';')
		sqlCommand += c;
}



bool Lexer::isAlphanumeric(char c)
{
	return (c >= 'A' && c <= 'z' || c >= '0' && c <= '9');
}

bool Lexer::isOperator(char c)
{
	return (operators.find(c) == std::string::npos);
}

bool Lexer::isPunctuation(char c)
{
	return (punctuation.find(c) == std::string::npos);
}

void Lexer::SetTokens()
{
	
}




Lexer::~Lexer()
{
}
