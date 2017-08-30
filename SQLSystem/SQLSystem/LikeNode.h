#pragma once
#include "IToken.h"
#include "AstNode.h"

class LikeNode : public AstNode
{
public:
  LikeNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
