#pragma once
#include"stdafx.h"
#include"ICommand.h"
class AstNode
{
public:

	
	AstNode(ICommand* aCommand) :mCommand(aCommand) {};
	AstNode();
	int GetPos();

	ICommand* mCommand;
	AstNode *left;
	AstNode *right;


	~AstNode();

};

