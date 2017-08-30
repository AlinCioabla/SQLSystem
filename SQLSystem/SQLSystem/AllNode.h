#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class AllNode : public AstNode
{
public:
  AllNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
