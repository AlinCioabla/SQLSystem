#include "ASTNode.h"



ASTNode::ASTNode()
{
	mType = Undefined;
	mLeft = nullptr;
	mRight = nullptr;
}


ASTNode::~ASTNode()
{
	delete mLeft;
	delete mRight;
}
