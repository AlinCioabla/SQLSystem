#include "stdafx.h"
#include "AstNode.h"
AstNode::AstNode(const AstNode & aAstNode)
{
  mToken = aAstNode.GetToken();
  mLeft  = aAstNode.GetLeft();
  mRight = aAstNode.GetRight();
}

void AstNode::SetToken(TokenPtr aToken)
{
  mToken = aToken;
}

void AstNode::SetLeft(AstNodePtr aLeft)
{
  mLeft = aLeft;
}

void AstNode::SetRight(AstNodePtr aRight)
{
  mRight = aRight;
}

AstNode::~AstNode()
{
}
