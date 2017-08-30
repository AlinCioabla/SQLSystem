#pragma once
#include "IToken.h"
#include "AstNode.h"

class Visitor;

class AndNode : public AstNode
{
public:
  AndNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};