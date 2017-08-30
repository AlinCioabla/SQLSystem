#include "stdafx.h"
#include "ColumnNode.h"
#include "Visitor.h"

void ColumnNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}

ColumnNode::~ColumnNode()
{
}
