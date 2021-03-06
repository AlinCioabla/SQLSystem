#pragma once
#include "IToken.h"
#include "AstNode.h"
class Visitor;
class ValuesNode : public AstNode
{
public:
  ValuesNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
