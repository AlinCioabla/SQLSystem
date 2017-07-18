#pragma once
#include"stdafx.h"
#include"IToken.h"

class ITokensTraversal {


public:


	
	virtual bool ReadFromFile(ifstream& aIn)=0;

	virtual bool Tokenize()=0;

	virtual string GetSqlCommand() const =0;
	
	virtual IToken* GetNextToken() = 0;

	virtual bool HasNext() const = 0;
	





};