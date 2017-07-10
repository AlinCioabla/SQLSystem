#include"stdafx.h"
#include "Lexer.h"
#include "Keyword.h"
#include "Punctuation.h"
#include "Operator.h"
#include "WhiteSpace.h"

Lexer::Lexer()
{
}

void Lexer::ReadFromFile(ifstream& aIn)
{
	char c;
	while (aIn.get(c))
	{
		mSqlCommand += c;
	}
	
}


bool Lexer::IsAlphanumeric(char aC)
{
	return (aC >= 'A' && aC <= 'z' || aC >= '0' && aC <= '9');
}

bool Lexer::IsOperator(char aC)
{
	return (mOperators.find(aC) != string::npos);
}

bool Lexer::IsPunctuation(char aC)
{
	return (mPunctuation.find(aC) != string::npos);
}

void Lexer::Tokenize()
{
	string temp;

	for (auto it : mSqlCommand)
	{
		if (IsAlphanumeric(it))
		{
			temp += it;
		}
		else
		{
			if (temp.length())
			{
				mTokens.push_back(new Keyword(temp));
				temp.clear();
			}

			if (it == ' ' || it == '\n')
				mTokens.push_back(new WhiteSpace(it));

			else
				if (IsOperator(it))
					mTokens.push_back(new Operator(it));

				else if (IsPunctuation(it))
					mTokens.push_back(new Punctuation(it));
		}
	}
}



Lexer::~Lexer()
{
}
