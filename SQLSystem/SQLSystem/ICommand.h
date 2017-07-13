#pragma once
#include"IToken.h"
#include"Keyword.h"

enum CommandType 
{
	BeginType,
	IntermediarType,
	FinalType

};

class ICommand
{

public:

	virtual void SetArguments(IToken* aTableName) = 0;
	virtual CommandType GetType() const = 0;
	virtual bool ExpectedNext(ICommand*  aNextCommand)const = 0;

};

