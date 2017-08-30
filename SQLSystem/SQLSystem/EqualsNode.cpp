#include "stdafx.h"
#include "EqualsNode.h"
#include "Visitor.h"

void EqualsNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
