#include "stdafx.h"
#include "MinusOpNode.h"
#include "Visitor.h"

void MinusOpNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
