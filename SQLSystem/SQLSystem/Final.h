#pragma once
#include "ICommand.h"
class Final :
	public ICommand
{
public:

	Final(IToken* aCommand) :mCommand(aCommand) {};

	void SetArguments(IToken* aTableName) override;
	CommandType GetType() const  override;
	bool ExpectedNext(ICommand* aNextCommand)const override;

	~Final();

private:
	vector<IToken*> mArguments;
	IToken* mCommand;
};

