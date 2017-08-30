#pragma once
#include "IToken.h"
#include "AstNode.h"

class Visitor;

class WhereNode : public AstNode
{
public:
  WhereNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
