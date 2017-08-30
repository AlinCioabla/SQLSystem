#pragma once
#include "IToken.h"
#include "AstNode.h"

class DivisionOpNode : public AstNode
{
public:
  DivisionOpNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};