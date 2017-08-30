#pragma once
#include "IToken.h"
#include "AstNode.h"

class ValueNode : public AstNode
{
public:
  ValueNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
