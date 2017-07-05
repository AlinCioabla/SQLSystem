#pragma once
#include "IToken.h"
class Operator :
	public IToken
{
public:
	Operator();
	TokenType GetType() override;
	~Operator();
};

