#pragma once
#include"stdafx.h"
#include"ICommand.h"
class AstNode
{
public:

	AstNode(IToken* aToken) :mToken(aToken) { mLeft = nullptr; mRight = nullptr; };
	AstNode() : mToken(nullptr), mLeft(nullptr), mRight(nullptr) {}
	AstNode* GetLeft()  const  { return mLeft; };
	AstNode* GetRight() const  { return mRight; };
	IToken*  GetToken() const { return mToken; };
	void SetToken(IToken *aToken);
	void SetLeft(AstNode * aLeft);
	void SetRight(AstNode *aRight);



	~AstNode();

private:

	IToken* mToken;
	AstNode* mLeft;
	AstNode* mRight;




};

