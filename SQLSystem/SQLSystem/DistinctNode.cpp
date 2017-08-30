#include "stdafx.h"
#include "DistinctNode.h"
#include "Visitor.h"

DistinctNode::~DistinctNode()
{
}

void DistinctNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
