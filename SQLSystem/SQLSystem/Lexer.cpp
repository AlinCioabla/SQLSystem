#include"stdafx.h"
#include "Lexer.h"



Lexer::Lexer()
{
}

void Lexer::ReadFromFile(ifstream & in)
{
	getline(in, sqlCommand, ';');
	
}



bool Lexer::isAlphanumeric(string s)
{
	char l, r;
	l = s[0]; r = s[s.size() - 1];
	if ((l >= 'A' && l <= 'z' || l >= '0' && l <= '9') && (r >= 'A' && r <= 'z' || r >= '0' && r <= '9'))
		return true;
	else return false;
}

bool Lexer::isOperator(string c)
{
	return (operators.find(c) != std::string::npos);
}

bool Lexer::isPunctuation(string c)
{
	return (punctuation.find(c) != std::string::npos);
}

void Lexer::SetTokens()
{
	string token;

	istringstream iss(sqlCommand);
	while (iss >> token) {
		cout << token;
		if (isOperator(token))
			cout << " Operator" << endl;
		else if (isPunctuation(token))
			cout << " is punctuation" << endl;
		else
			if (isAlphanumeric(token))
				cout << " is word" << endl;
			else
				for (auto it : token) {
					string(it);
					token.SetTokens();
				}

	}
}




Lexer::~Lexer()
{
}
