#pragma once
#include "IToken.h"
#include "AstNode.h"

class InvalidNode : public AstNode
{
public:
  InvalidNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};