#include "stdafx.h"
#include "MultiplicationOpNode.h"
#include "Visitor.h"

void MultiplicationOpNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
