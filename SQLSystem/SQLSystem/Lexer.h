#pragma once
#ifndef _LEXER_
#define _LEXER_
#include"IToken.h"
#include"Operator.h"

class Lexer
{
public:

	vector<IToken*> tokens;

	Lexer();

	void ReadFromFile(ifstream& in);
	void SetTokens();

	bool isAlphanumeric(string c);
	bool isOperator(string c);
	bool isPunctuation(string c);

	~Lexer();
private:
	string  sqlCommand;

	string punctuation = { ".,'?""&!" };
	string operators = { "+-*/=^%<>" };
	string alphanumerics = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmopqrstuvwxyz0123456789" };

};
#endif // !_LEXER_
