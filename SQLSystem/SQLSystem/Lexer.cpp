#include"stdafx.h"
#include "Lexer.h"



Lexer::Lexer()
{
}

string Lexer::ReadFromFile(ifstream & in)
{
	char c;
	string sqlCommand;
	while (in >> c && c != ';')
		sqlCommand += c;
	return sqlCommand;
}

void Lexer::SetTokens(string sqlCommand)
{


}


Lexer::~Lexer()
{
}
