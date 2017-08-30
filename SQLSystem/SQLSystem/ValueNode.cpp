#include "stdafx.h"
#include "ValueNode.h"
#include "Visitor.h"

void ValueNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
