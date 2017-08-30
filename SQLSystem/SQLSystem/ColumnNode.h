#pragma once
#include "IToken.h"
#include "AstNode.h"

class ColumnNode : public AstNode
{
public:
  ColumnNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
