#pragma once
#ifndef _LEXER_
#define _LEXER_
#include"IToken.h"
#include"Keyword.h"
#include "Keyword.h"
#include "Punctuation.h"
#include "Operator.h"
#include "WhiteSpace.h"
#include"ITokensTraversal.h"


using namespace std;

class Lexer:
	public ITokensTraversal
{
public:
	Lexer();

	//Checks if the file can be read and sets mSqlCommand
	bool ReadFromFile(ifstream& aIn);

	//This one tokenize mSqlCommand and stores the tokens in mTokens 
	bool Tokenize();
	string GetSqlCommand() const { return mSqlCommand; };
	vector<IToken*> mTokens;
	IToken* GetNextToken() const ;

	bool HasNext() const ;
	~Lexer();
private:
	string mSqlCommand;

};
#endif // !_LEXER_
