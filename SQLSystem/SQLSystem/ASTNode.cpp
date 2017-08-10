#include "stdafx.h"
#include "AstNode.h"
#include "IToken.h"

AstNode::AstNode(const AstNode & aAstNode)
{
}

void AstNode::SetToken(TokenPtr aToken)
{
  mToken = move(aToken);
}

void AstNode::SetLeft(AstNodePtr aLeft)
{
  mLeft = move(aLeft);
}

void AstNode::SetRight(AstNodePtr aRight)
{
  mRight = move(aRight);
}

AstNode::~AstNode()
{
}
