#include "Parser.h"





void Parser::StartParsing()
{
}

void Parser::SetKeywords(ifstream &instr)
{
	string line;
	while (getline(instr, line)) 
	{
		mKeywords.push_back(line);
	}
}

const vector<string> Parser::GetKeywords() 
{
	return mKeywords;
}

Parser::~Parser()
{
}
