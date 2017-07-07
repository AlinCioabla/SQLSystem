#include"stdafx.h"
#include "Lexer.h"

#include"Keyword.h"
#include "Punctuation.h"
#include "Operator.h"

Lexer::Lexer()
{
}

void Lexer::ReadFromFile(ifstream & in)
{
	getline(in, sqlCommand, ';');
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
	
	int i, j=0;
	string temp;

	for (i = 0; i < sqlCommand.length(); i++)
	{
		if (isAlphanumeric(sqlCommand[i]))
		{
			temp += sqlCommand[i];
		}
		else
		{	
			if (temp.length())
			{
				
				tokens.push_back(new Keyword(temp));
				
				temp.clear();
			}


			if (sqlCommand[i] != ' ')
			{
				if (isOperator(sqlCommand[i]))
					tokens.push_back(new Punctuation(sqlCommand[i]));
				else if(isPunctuation(sqlCommand[i]))
					tokens.push_back(new Operator(sqlCommand[i]));
			}
		}
	}
	



}

void Lexer::PrintTokens()
{
	for_each(tokens.begin(), tokens.end(), [](IToken *token) { token->PrintWord(); });
}




Lexer::~Lexer()
{
}
