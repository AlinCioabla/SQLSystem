#pragma once
#include "IToken.h"
#include "AstNode.h"

class CommaNode : public AstNode
{
public:
  CommaNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};