#pragma once
#ifndef _LEXER_
#define _LEXER_
#include"IToken.h"

class Lexer
{
public:

	vector<IToken*> tokens;

	Lexer();

	string ReadFromFile(ifstream& in);
	void SetTokens(string sqlCommand);

	~Lexer();
};
#endif // !_LEXER_
