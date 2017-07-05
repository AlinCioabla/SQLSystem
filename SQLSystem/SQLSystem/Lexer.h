#pragma once
#ifndef _LEXER_
#define _LEXER_
#include"IToken.h"

class Lexer
{
public:

	vector<IToken*> tokens;

	Lexer();

	void ReadFromFile(ifstream& in);
	void SetTokens();

	~Lexer();
private:
	string sqlCommand;
};
#endif // !_LEXER_
