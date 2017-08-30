#include "stdafx.h"
#include "OrNode.h"
#include "Visitor.h"

void OrNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
