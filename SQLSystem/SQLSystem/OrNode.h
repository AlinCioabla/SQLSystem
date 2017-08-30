#pragma once
#include "IToken.h"
#include "AstNode.h"

class OrNode : public AstNode
{
public:
  OrNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
