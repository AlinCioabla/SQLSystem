#pragma once
#include"stdafx.h"
#include"ICommand.h"
class AstNode
{
public:

	vector<AstNode*> mChildren;
	AstNode(ICommand* aCommand) :mCommand(aCommand) {};
	AstNode();

	ICommand* mCommand;

	~AstNode();

};

