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

	bool isAlphanumeric(char c);
	bool isOperator(char c);
	bool isPunctuation(char c);

	~Lexer();
private:
	string sqlCommand;

	string punctuation = { ".,'?""&!" };
	string operators = { "+-*/=^%" };

};
#endif // !_LEXER_
