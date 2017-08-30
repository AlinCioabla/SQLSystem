#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class NumberNode : public AstNode
{
public:
  NumberNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};