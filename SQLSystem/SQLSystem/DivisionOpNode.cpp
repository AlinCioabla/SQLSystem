#include "stdafx.h"
#include "DivisionOpNode.h"
#include "Visitor.h"

void DivisionOpNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
