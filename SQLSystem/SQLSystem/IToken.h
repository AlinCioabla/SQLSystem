#pragma once
enum TokenType
{
	Keyword,
	Operator,
	Punctuation
};


class IToken
{
public:
	IToken();
	

	virtual TokenType GetType() = 0;


	virtual ~IToken();
};

