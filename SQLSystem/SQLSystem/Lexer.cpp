#include"stdafx.h"
#include "Lexer.h"



Lexer::Lexer()
{
}

void Lexer::ReadFromFile(ifstream & in)
{
	char c;
	while (in >> c && c != ';') {
		sqlCommand += c;
	}
}

void Lexer::SetTokens()
{
	for_each(sqlCommand.begin(), sqlCommand.end(),
				[](char word){
		
		return true;
		});
			

}


Lexer::~Lexer()
{
}
