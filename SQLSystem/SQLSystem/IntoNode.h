#pragma once
#include "IToken.h"
#include "AstNode.h"

class IntoNode : public AstNode
{
public:
  IntoNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
