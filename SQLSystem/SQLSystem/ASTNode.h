#pragma once

#include "stdafx.h"

enum ASTNodeType
{
	Undefined,
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv,
	UnaryMinus,
	NumberValue
};

class ASTNode
{
public:






	ASTNodeType mType;
	string mWord;
	ASTNode* mLeft;
	ASTNode* mRight;



};


