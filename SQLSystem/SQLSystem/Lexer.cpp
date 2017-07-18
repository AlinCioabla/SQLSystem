#include"stdafx.h"
#include "Lexer.h"


Lexer::Lexer()
{
}

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
	string _temp;
	
	// Iterate through all the initial input string characters
	for (auto it : mSqlCommand)
	{
		// If we find an alphanumeric character we add it to the
		// _temp string
		if (IsAlphanumeric(it))
		{
			_temp += it;
		}
		// If we find a delimiter, we store the created _temp string as
		// a keyword token, then empty it
		else
		{
			if (_temp.length())
			{
				mTokens.push_back(new Keyword(_temp));
				_temp.clear();
			}

			// Then we create the appropiate token for the given non alphanumeric
			// character from the input
			if (it == ' ' || it == '\n')
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

	return true;

}


Lexer::~Lexer()
{
	for (auto token : mTokens)
		delete token;
}
