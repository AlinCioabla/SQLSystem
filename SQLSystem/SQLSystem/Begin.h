#pragma once
#include "ICommand.h"
class Begin :
	public ICommand
{
public:
	
	Begin(IToken* aCommand) :mCommand(aCommand) {};

	
	CommandType GetCommandType() const  override;
	bool ExpectedNext(ICommand* aNextCommand)const override;


	~Begin();

	vector<IToken*> mArguments;

	IToken* mCommand;

};

