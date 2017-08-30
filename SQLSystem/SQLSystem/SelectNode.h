#pragma once
#include "IToken.h"
#include "AstNode.h"
#include "Punctuation.h"
class Visitor;

class SelectNode : public AstNode
{
public:
  SelectNode(TokenPtr & aToken)
    : AstNode(aToken)
  {
  }

  void Accept(Visitor & aVisitor) override;
};
