#include "Begin.h"





void Begin::SetArguments(IToken* aTableName)
{
}

CommandType Begin::GetType() const
{
	return CommandType::BeginType;
}

bool Begin::ExpectedNext(ICommand*  aNextCommand) const
{
	return(aNextCommand->GetType() == IntermediarType || aNextCommand->GetType() == FinalType);
	
}

Begin::~Begin()
{
}
