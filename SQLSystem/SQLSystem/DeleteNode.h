#pragma once
#include "IToken.h"
#include "AstNode.h"

class DeleteNode : public AstNode
{
public:
  DeleteNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
