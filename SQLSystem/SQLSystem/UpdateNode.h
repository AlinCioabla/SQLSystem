#pragma once
#include "IToken.h"
#include "AstNode.h"

class UpdateNode : public AstNode
{
public:
  UpdateNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
