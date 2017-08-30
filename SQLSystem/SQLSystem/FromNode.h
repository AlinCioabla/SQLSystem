#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class FromNode : public AstNode
{
public:
  FromNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
