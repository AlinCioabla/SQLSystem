#pragma once
#include"stdafx.h"
#include"Lexer.h"
#include"ICommand.h"
#include"Begin.h"
#include"Intermediar.h"
#include"Final.h"
#include"AstNode.h"

class Parser
{
public:

	Parser(vector <IToken*> &tokens):mKeywords(tokens){ StartParsing(); };

	void SetCommands();

	bool StartParsing();
	
	bool isBegin(IToken *aToken);
	bool isIntermediar(IToken *aToken);
	bool isFinal(IToken *aToken);

	vector<IToken*> const GetKeywords();

	~Parser();
private:

	vector<ICommand*> mCommands;
	vector<IToken*> mKeywords;

	vector<string> mBegin{"SELECT","DELETE","UPDATE","INSERT"};
	vector<string> mIntermediar{"FROM","WHERE","SET"};
	vector<string> mFinal{"LIKE","OR","AND","NOT","+","-","%"};

};

