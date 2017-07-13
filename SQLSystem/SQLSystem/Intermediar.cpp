#include "Intermediar.h"





void Intermediar::SetArguments(IToken* aTableName)
{
	mArguments.push_back(aTableName);
}

CommandType Intermediar::GetType() const
{
	return CommandType::IntermediarType;
}

bool Intermediar::ExpectedNext(ICommand*  aNextCommand) const
{
	return(aNextCommand->GetType() == IntermediarType || aNextCommand->GetType() == FinalType);
}

Intermediar::~Intermediar()
{
}
