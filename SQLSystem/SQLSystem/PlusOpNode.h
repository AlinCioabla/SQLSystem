#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class PlusOpNode : public AstNode
{
public:
  PlusOpNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};