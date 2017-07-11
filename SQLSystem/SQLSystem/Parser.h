#pragma once
#include"stdafx.h"
#include"Lexer.h"



class Parser
{
public:

	Parser(vector <IToken*> &tokens) { StartParsing(); };
	void StartParsing();
	void SetKeywords(ifstream &instr);//Sets mKeywords with sql commands;
	vector<string> const GetKeywords();

	~Parser();
private:
	vector<string> mKeywords;

};

