#pragma once
#include"stdafx.h"
#include"ICommand.h"
class AstNode
{
public:

	AstNode(IToken* aToken) :mToken(aToken) {};
	AstNode* GetLeft() { return mLeft; };
	AstNode* GetRight() { return mRight; };
	IToken*  GetToken() { return mToken; };
	void SetToken(IToken *aToken);
	void SetLeft(AstNode * aLeft);
	void SetRight(AstNode *aRight);

	AstNode();

	~AstNode();

private:

	IToken* mToken;
	AstNode* mLeft;
	AstNode* mRight;




};

