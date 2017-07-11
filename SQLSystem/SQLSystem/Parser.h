#pragma once
#include"stdafx.h"
#include"Lexer.h"



class Parser
{
public:

	Parser(vector <IToken*> &tokens) { StartParsing(); };

	//Sets mKeywords with sql commands;
	void SetKeywords(ifstream &instr);
	void StartParsing();
	vector<string> const GetKeywords();

	~Parser();
private:
	vector<string> mKeywords;

};

