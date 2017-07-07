#include"stdafx.h"
#include "Lexer.h"
#include "Keyword.h"
#include "Punctuation.h"
#include "Operator.h"
#include "WhiteSpace.h"

Lexer::Lexer()
{
}

void Lexer::ReadFromFile(ifstream & in)
{
	char c;
	while (in.get(c))
	{
		sqlCommand += c;
	}
	
}


bool Lexer::isAlphanumeric(char c)
{
	return (c >= 'A' && c <= 'z' || c >= '0' && c <= '9');
}

bool Lexer::isOperator(char c)
{
	return (operators.find(c) != std::string::npos);
}

bool Lexer::isPunctuation(char c)
{
	return (punctuation.find(c) != std::string::npos);
}

void Lexer::SetTokens()
{
	string temp;

	for (auto it : sqlCommand)
	{
		if (isAlphanumeric(it))
		{
			temp += it;
		}
		else
		{
			if (temp.length())
			{
				tokens.push_back(new Keyword(temp));
				temp.clear();
			}

			if (it == ' ')
				tokens.push_back(new WhiteSpace(it));

			else
				if (isOperator(it))
					tokens.push_back(new Operator(it));

				else if (isPunctuation(it))
					tokens.push_back(new Punctuation(it));
		}
	}
}

void Lexer::PrintTokenTypes()
{
	for_each(tokens.begin(), tokens.end(), [](IToken *token) { token->PrintWord(); });
}

Lexer::~Lexer()
{
}
