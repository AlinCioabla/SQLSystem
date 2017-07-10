#pragma once
#ifndef _LEXER_
#define _LEXER_
#include"IToken.h"
#include"Keyword.h"
using namespace std;

class Lexer
{
public:

	vector<IToken*> mTokens;

	Lexer();

	void ReadFromFile(ifstream& aIn);
	void Tokenize();
	string GetSqlCommand() { return mSqlCommand; };

	bool IsAlphanumeric(char aC);
	bool IsOperator(char aC);
	bool IsPunctuation(char aC);

	~Lexer();
private:
	string mSqlCommand;
	string mPunctuation = { ".,?""'&!;:_()" };
	string mOperators = { "+-*/=^%<>" };
	string mAlphanumerics = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmopqrstuvwxyz0123456789" };

};
#endif // !_LEXER_
