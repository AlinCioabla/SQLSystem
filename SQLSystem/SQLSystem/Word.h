#pragma once
#include "ICommand.h"
class Word :
	public ICommand
{
public:
	Word(IToken* aWord) :mWord(aWord) {};

	void SetArguments(IToken* aTableName) override;
	CommandType GetCommandType() const  override;
	bool ExpectedNext(ICommand* aNextCommand)const override;

	~Word();
private: 
	IToken* mWord;
};

