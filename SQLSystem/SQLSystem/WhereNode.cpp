#include "stdafx.h"
#include "WhereNode.h"
#include "Visitor.h"

void WhereNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}

WhereNode::~WhereNode()
{
}
