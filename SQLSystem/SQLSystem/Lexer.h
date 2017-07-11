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

	bool ReadFromFile(ifstream& aIn);//Checks if the file can be read and sets mSqlCommand
	bool Tokenize();//This one tokenize mSqlCommand and stores the tokens in mTokens 
	string GetSqlCommand() { return mSqlCommand; };

	//Checks if a token is an alphanumeric, operator or punctuation
	bool IsAlphanumeric(char aC);
	bool IsOperator(char aC);
	bool IsPunctuation(char aC);

	~Lexer();
private:
	string mSqlCommand;
	string mPunctuation = { ".,?""'&!;:_()" };
	string mOperators = { "+-*/=^%<>" };

};
#endif // !_LEXER_
