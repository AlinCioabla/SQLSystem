#include "Word.h"





void Word::SetArguments(IToken * aTableName)
{
}

CommandType Word::GetCommandType() const
{
	return CommandType();
}

bool Word::ExpectedNext(ICommand * aNextCommand) const
{
	return false;
}

Word::~Word()
{
}
