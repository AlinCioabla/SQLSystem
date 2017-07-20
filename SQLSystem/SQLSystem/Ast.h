#pragma once
#include"AstNode.h"

class Ast
{
public:
	
	Ast(AstNode *aRoot) :mRoot(aRoot) {};

	AstNode* NewNode(IToken* aToken);
	AstNode* InsertNode(AstNode *aNode, IToken* aToken);
	void PrintInorder(AstNode *aRoot);
	void Display(AstNode *current, int indent);
	AstNode* GetRoot()const { return mRoot; };


	~Ast();
private:
	AstNode *mRoot;
};

