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
	bool ReadFromFile(ifstream& aIn);
	bool Tokenize();
	string GetSqlCommand() { return mSqlCommand; };

	~Lexer();
private:
	bool IsAlphanumeric(char aC);
	bool IsOperator(char aC);
	bool IsPunctuation(char aC);
	string mSqlCommand;
	string mPunctuation = { ".,?""'&!;:_()" };
	string mOperators = { "+-*/=^%<>" };
	string mAlphanumerics = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmopqrstuvwxyz0123456789" };

};
#endif // !_LEXER_
