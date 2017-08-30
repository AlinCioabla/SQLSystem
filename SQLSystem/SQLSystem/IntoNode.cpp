#include "stdafx.h"
#include "IntoNode.h"
#include "Visitor.h"

void InsertNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}

IntoNode::~IntoNode()
{
}
