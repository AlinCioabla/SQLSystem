#include "stdafx.h"
#include "InvalidNode.h"
#include "Visitor.h"

void InvalidNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
