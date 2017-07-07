#pragma once
#include"Lexer.h"



class Parser
{
public:

	Parser(vector <IToken*> &tokens) { StartParsing(); };
	void StartParsing();

	~Parser();
private:

};

