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
	for_each(sqlCommand.begin(), sqlCommand.end(),
				[](char word){
		cout << word;
		return true;
		});
			

}


Lexer::~Lexer()
{
}
