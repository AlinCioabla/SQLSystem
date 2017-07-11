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

	//Checks if the file can be read and sets mSqlCommand
	bool ReadFromFile(ifstream& aIn);

	//This one tokenize mSqlCommand and stores the tokens in mTokens 
	bool Tokenize();
	string GetSqlCommand() const { return mSqlCommand; };

	//Checks if a token is an alphanumeric, operator or punctuation
	bool IsAlphanumeric(char aC) const;
	bool IsOperator(char aC) const;
	bool IsPunctuation(char aC) const;

	~Lexer();
private:
	string mSqlCommand;
	string mPunctuation = { ".,?""'&!;:_()" };
	string mOperators = { "+-*/=^%<>" };

};
#endif // !_LEXER_
