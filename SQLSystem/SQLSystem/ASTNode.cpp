#include "stdafx.h"
#include "AstNode.h"
void AstNode::SetToken(IToken * aToken)
{
  mToken = aToken;
}

void AstNode::SetLeft(AstNode * aLeft)
{
  mLeft = aLeft;
}

void AstNode::SetRight(AstNode * aRight)
{
  mRight = aRight;
}

AstNode::~AstNode()
{
  delete mToken;
}
