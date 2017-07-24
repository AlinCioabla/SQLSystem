#include "Intermediar.h"

void Intermediar::SetArguments(IToken* aTableName)
{
	mArguments.push_back(aTableName);
}

CommandType Intermediar::GetCommandType() const
{
	return CommandType::IntermediarType;
}

bool Intermediar::ExpectedNext(ICommand*  aNextCommand) const
{
	return(aNextCommand->GetCommandType() == IntermediarType || aNextCommand->GetCommandType() == FinalType);
}

Intermediar::~Intermediar()
{
}
