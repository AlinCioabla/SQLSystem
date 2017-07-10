#include "LexerTester.h"




bool LexerTester::TestTokens()
{
	string TokensVector;
	string InitialCommand = m_lexer.GetSqlCommand();
	for_each(m_lexer.mTokens.begin(), m_lexer.mTokens.end(), 
		[&](IToken * token)
	{
		TokensVector+=(token->GetWord());
	}
		);
	//cout << tokensVector << endl << endl << initialCommand<<endl;



	return TokensVector == InitialCommand;
}

LexerTester::~LexerTester()
{
}
