#include "LexerTester.h"




bool LexerTester::TestLexer() 
{
	// Check if the file is valid
	bool readFromFileStatus = mLexer.ReadFromFile(mIn);
	if (!readFromFileStatus)
	{
		cout << "Cannot read from given file."<< endl;
		return false;
	}

	// Start tokenizing the input
	bool tokenizeStatus = mLexer.Tokenize();
	if (!tokenizeStatus)
	{
		cout << "Error tokenizing. Unexpected symbol"<<endl;
		return false;
	}

	// Create 2 temporary strings
	// The method will try recomposing the tokens into the original input
	// If it succeeds, it will return true

	string _TokensVector;
	string _InitialCommand = mLexer.GetSqlCommand();

	// Concatenate all the strings contained by the tokens
	for_each(mLexer.mTokens.begin(), mLexer.mTokens.end(), 
		[&_TokensVector](IToken * token)
	{
		_TokensVector+=(token->GetWord());
	}
		);

	// Check if the resulted concatenated string matches the input
	bool TestTokensStatus = (_TokensVector == _InitialCommand);
	if (!TestTokensStatus)
	{
		cout << "Failed to tokenize properly." << endl;
		return false;
	}

	return true;

}

LexerTester::~LexerTester()
{
}
