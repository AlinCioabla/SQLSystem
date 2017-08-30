#include "stdafx.h"
#include "AllNode.h"
#include "Visitor.h"

void AllNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}

AllNode::~AllNode()
{
}
