#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class InsertNode : public AstNode
{
public:
  InsertNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
