#include "stdafx.h"
#include "AndNode.h"
#include "Visitor.h"

void AndNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
