#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class ValueNode : public AstNode
{
public:
  ValueNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
