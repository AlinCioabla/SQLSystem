#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class EqualsNode : public AstNode
{
public:
  EqualsNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};