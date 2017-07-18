#include "LexerTester.h"




bool LexerTester::TestTokens() 
{
	// Check if the file is valid
	bool readFromFileStatus = mLexer.ReadFromFile(mIn);
	if (!readFromFileStatus)
	{
		cout << "Cannot read from given file."<< endl;
		return false;
	}

	// Start tokenizing the input
	bool _tokenizeSucces = mLexer.Tokenize();
	if (!_tokenizeSucces)
	{
		cout << "Tokenization ended unexpectedly.";
		return false;
	}

	// Create 2 temporary strings
	// The method will try recomposing the tokens into the original input
	// If it succeeds, it will return true

	string _tokensVector;
	string _initialCommand = mLexer.GetSqlCommand();

	// Concatenate all the strings contained by the tokens
	for (auto it : mLexer.mTokens)
		_tokensVector += it->GetWord();

	// Check if the resulted concatenated string matches the input
	bool TestTokensStatus = (_tokensVector == _initialCommand);
	
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
