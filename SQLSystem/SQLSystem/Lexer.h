#pragma once
#ifndef _LEXER_
#define _LEXER_
#include"IToken.h"
#include"Keyword.h"
using namespace std;

class Lexer
{
public:

	vector<IToken*> tokens;

	Lexer();

	void ReadFromFile(ifstream& in);
	void SetTokens();
	string getSqlCommand() { return sqlCommand; };

	bool isAlphanumeric(char c);
	bool isOperator(char c);
	bool isPunctuation(char c);

	~Lexer();
private:
	string sqlCommand;
	string punctuation = { ".,?""'&!;:_()" };
	string operators = { "+-*/=^%<>" };
	

};
#endif // !_LEXER_
