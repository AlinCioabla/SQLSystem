#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class UpdateNode : public AstNode
{
public:
  UpdateNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
