#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class PredicateNode : public AstNode
{
public:
  PredicateNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};