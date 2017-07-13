#include "AstNode.h"

AstNode::~AstNode()
{
	for (auto it : mChildren)
		delete it;
}
