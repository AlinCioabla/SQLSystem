#pragma once
#include "IToken.h"
class Keyword :
	public IToken
{
public:
	Keyword();
	TokenType GetType() override;
	~Keyword();

};

