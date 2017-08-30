#include "stdafx.h"
#include "PlusOpNode.h"
#include "Visitor.h"

void PlusOpNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
