#include "AstNode.h"

AstNode::AstNode()
{
}

AstNode::~AstNode()
{
	for (auto it : mChildren)
		delete it;
}
