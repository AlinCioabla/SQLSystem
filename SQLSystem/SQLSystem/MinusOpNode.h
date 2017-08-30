#pragma once
#include "IToken.h"
#include "AstNode.h"

class MinusOpNode : public AstNode
{
public:
  MinusOpNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};