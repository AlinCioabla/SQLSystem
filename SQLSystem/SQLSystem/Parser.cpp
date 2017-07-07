#include "Parser.h"





void Parser::StartParsing()
{
}

void Parser::SetKeywords(ifstream & instr)
{
	string line;
	while (getline(instr, line)) 
	{
		cout << line<<endl;
		keywords.push_back(line);
	}
}

vector<string> Parser::GetKeywords()
{
	return keywords;
}

Parser::~Parser()
{
}
