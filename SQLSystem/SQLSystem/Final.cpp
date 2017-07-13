#include "Final.h"




void Final::SetArguments(IToken* aTableName)
{
}

CommandType Final::GetType() const
{
	return CommandType::IntermediarType;
}

bool Final::ExpectedNext(ICommand* aNextCommand) const
{
	return(aNextCommand->GetType() == FinalType);
}

Final::~Final()
{
}
