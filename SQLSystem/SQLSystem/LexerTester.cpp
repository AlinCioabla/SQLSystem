#include "LexerTester.h"




bool LexerTester::TestTokens()
{
	string tokensVector, initialCommand=m_lexer.getSqlCommand();
	for_each(m_lexer.tokens.begin(), m_lexer.tokens.end(), 
		[&](IToken * token)
	{
		tokensVector+=(token->GetWord());
	}
		);
	//cout << tokensVector << endl << endl << initialCommand<<endl;



	return tokensVector == initialCommand;
}

LexerTester::~LexerTester()
{
}
