#pragma once
#include "IToken.h"
class Punctuation :
	public IToken
{
public:
	Punctuation();
	TokenType GetType() override;
	~Punctuation();
};

