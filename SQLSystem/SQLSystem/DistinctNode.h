#pragma once
#include "IToken.h"
#include "AstNode.h"

class DistinctNode : public AstNode
{
public:
  DistinctNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
