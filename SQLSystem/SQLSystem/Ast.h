#pragma once
#include"AstNode.h"

class Ast
{
public:
	Ast(AstNode aNode) :mNode(aNode) {};
	void Insert(AstNode aNode,int aN);

	~Ast();
private:
	AstNode mNode;
};

