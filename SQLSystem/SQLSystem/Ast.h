#pragma once
#include"AstNode.h"

class Ast
{
public:
	
	Ast(AstNode *aRoot) :mRoot(aRoot) {};

	AstNode* NewNode(IToken* aToken);
	AstNode* InsertNode(AstNode *aNode, IToken* aToken);
	void printTree(AstNode * current);
	void printNodeValue(AstNode *current);
	void printTree( bool isRight, string indent);

	void Display(AstNode *current, int indent);
	AstNode* GetRoot()const { return mRoot; };


	~Ast();
private:
	AstNode *mRoot;
};

