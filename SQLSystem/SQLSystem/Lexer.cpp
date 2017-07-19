#include"stdafx.h"
#include "Lexer.h"
#include "Helpers.h"



// Read the input from a given file and store it in the member string
// of the class mSqlCommand
// If the file is not valid the method returns false and exits.

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


// Split the input string into different types
bool Lexer::Tokenize()
{
	// Temporary string
	string temp;
	
	// Iterate through all the initial input string characters
	for (auto it : mSqlCommand)
	{
		// If we find an alphanumeric character we add it to the
		// _temp string
		if (IsAlphanumeric(it))
		{
			temp += it;
		}
		// If we find a delimiter, we store the created _temp string as
		// a keyword token, then empty it
		else
		{
			if (temp.length())
			{
				if (IsKeyword(temp))
					mTokens.push_back(new Keyword(temp));
				else
					mTokens.push_back(new Identifier(temp));
				temp.clear();
			}

			// Then we create the appropiate token for the given non alphanumeric
			// character from the input
		
			if (IsWhitespace(it))
				mTokens.push_back(new WhiteSpace(it));

			else
				if (IsOperator(it))
					mTokens.push_back(new Operator(it));

				else if (IsPunctuation(it))
					mTokens.push_back(new Punctuation(it));
				else
					// If we find a character we do not recognize, the tokenizer stops
					// and returns false
					return false;
		}

	}
	mIndex = mTokens.begin();
	return true;

}

IToken * Lexer::GetNextToken() 
{
	if (this->HasNext()) {
		if (!returnedFirstToken)
		{
			returnedFirstToken = true;
		}
		else
			advance(mIndex, 1);
		return *mIndex;
	}
	else 
		return nullptr;

}


bool Lexer::HasNext() const
{
	if (mIndex != mTokens.end()-1)

		return true;
	else
		return false;
}

Lexer::~Lexer()
{
	for (auto token : mTokens)
		delete token;
}
