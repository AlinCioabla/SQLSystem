#include "LexerTester.h"




bool LexerTester::TestTokens() 
{
	
	bool readFromFileStatus = mLexer.ReadFromFile(mIn);
	if (!readFromFileStatus)
	{
		cout << "Cannot read from given file."<< endl;
		return false;
	}

	mLexer.Tokenize();


	string _TokensVector;
	string _InitialCommand = mLexer.GetSqlCommand();
	for_each(mLexer.mTokens.begin(), mLexer.mTokens.end(), 
		[&_TokensVector](IToken * token)
	{
		_TokensVector+=(token->GetWord());
	}
		);

	bool TestTokensStatus = (_TokensVector == _InitialCommand);
	if (!TestTokensStatus)
	{
		cout << "Failed to tokenize." << endl;
		return false;
	}

	return true;

}

LexerTester::~LexerTester()
{
}
