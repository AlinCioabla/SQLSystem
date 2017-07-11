#include"stdafx.h"
#include "Lexer.h"
#include "Keyword.h"
#include "Punctuation.h"
#include "Operator.h"
#include "WhiteSpace.h"

Lexer::Lexer()
{
}

bool Lexer::ReadFromFile(ifstream& aIn)
{
	if (!aIn)
		return false;

	char c;
	while (aIn.get(c))
	{
		mSqlCommand += c;
	}
	return true;
	
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

bool Lexer::Tokenize()
{
	string _temp;
	
	for (auto it : mSqlCommand)
	{
		if (IsAlphanumeric(it))
		{
			_temp += it;
		}
		else
		{
			if (_temp.length())
			{
				mTokens.push_back(new Keyword(_temp));
				_temp.clear();
			}

			if (it == ' ' || it == '\n')
				mTokens.push_back(new WhiteSpace(it));

			else
				if (IsOperator(it))
					mTokens.push_back(new Operator(it));

				else if (IsPunctuation(it))
					mTokens.push_back(new Punctuation(it));
				else
					return false;
		}

	}

	return true;

}


Lexer::~Lexer()
{
}
