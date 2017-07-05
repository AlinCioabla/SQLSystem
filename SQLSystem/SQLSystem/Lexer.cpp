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

void Lexer::SetTokens()
{
	string currentToken;

	for_each(sqlCommand.begin(), sqlCommand.end(), [](char &word){
		
		});
			

}

bool Lexer::isAlphanumeric(char c)
{
	return (c >= 'A' && c <= 'z' || c >= '0' && c <= '9');
}

bool Lexer::isOperator(char c)
{
	return (operators.find(c) != nullptr);
}


Lexer::~Lexer()
{
}
