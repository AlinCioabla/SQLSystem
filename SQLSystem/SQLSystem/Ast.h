#pragma once
#include"AstNode.h"

class Ast
{
public:
	Ast(AstNode aRoot) :mRoot(aRoot) {};
	void Insert(AstNode aNode,int aN);

	~Ast();
private:
	AstNode mRoot;
};

