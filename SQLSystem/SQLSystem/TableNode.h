#pragma once
#include "IToken.h"
#include "AstNode.h"

class TableNode : public AstNode
{
public:
  TableNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
