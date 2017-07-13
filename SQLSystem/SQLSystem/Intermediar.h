#pragma once
#include "ICommand.h"
class Intermediar :
	public ICommand
{
public:

	Intermediar(IToken* aCommand) :mCommand(aCommand) {};

	void SetArguments(IToken* aTableName) override;
	CommandType GetType() const  override;
	bool ExpectedNext(ICommand*  aNextCommand)const override;

	~Intermediar();

private:
	vector<IToken*> mArguments;
	IToken* mCommand;
};

