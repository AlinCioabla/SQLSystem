#include "stdafx.h"
#include "AstNode.h"
#include "IToken.h"
#include "Visitor.h"

void AstNode::SetToken(TokenPtr & aToken)
{
  mToken = move(aToken);
}

void AstNode::SetLeft(const AstNodePtr & aLeft)
{
  mLeft = move(aLeft);
}

void AstNode::SetRight(const AstNodePtr & aRight)
{
  mRight = move(aRight);
}

AstNode::~AstNode() = default;
