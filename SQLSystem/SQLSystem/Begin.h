#pragma once
#include "ICommand.h"
class Begin :
	public ICommand
{
public:
	
	Begin(IToken* aCommand) :mCommand(aCommand) {};

	void SetArguments(IToken* aTableName) override;
	CommandType GetType() const  override;
	bool ExpectedNext(ICommand* aNextCommand)const override;

	~Begin();

private:
	vector<IToken*> mArguments;
	IToken* mCommand;

};

