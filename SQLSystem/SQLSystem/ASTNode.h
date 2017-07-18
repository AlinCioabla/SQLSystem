#pragma once
#include"stdafx.h"
#include"ICommand.h"
class AstNode
{
public:

	
	AstNode(IToken* aToken) :mToken(aToken) {};
	AstNode();
	

	IToken* mToken;
	AstNode *left;
	AstNode *right;
	int mOk;


	~AstNode();

};

