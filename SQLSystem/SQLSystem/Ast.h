#pragma once
#include"AstNode.h"

class Ast
{
public:
	Ast(AstNode *aNode) :mRoot(aNode) {};
	void Insert(AstNode *aAstNode);
	AstNode* CreateNode(int val, IToken* aToken);



	~Ast();
private:
	AstNode *mRoot;
};

