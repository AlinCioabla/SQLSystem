#include "stdafx.h"
#include "DistinctNode.h"
#include "Visitor.h"

void DistinctNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
