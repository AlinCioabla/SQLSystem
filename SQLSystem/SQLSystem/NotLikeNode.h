#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class NotLikeNode : public AstNode
{
public:
  NotLikeNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};