#pragma once
#include"IToken.h"
#include"Keyword.h"

enum CommandType 
{
	BeginType,
	IntermediarType,
	FinalType,
	WordType

};

class ICommand
{

public:

	virtual void SetArguments(IToken* aTableName) = 0;
	virtual CommandType GetCommandType() const = 0;
	virtual bool ExpectedNext(ICommand*  aNextCommand)const = 0;

};

