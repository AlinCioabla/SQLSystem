#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class MultiplicationOpNode : public AstNode
{
public:
  MultiplicationOpNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};