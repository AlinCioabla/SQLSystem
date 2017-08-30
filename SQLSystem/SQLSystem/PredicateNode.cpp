#include "stdafx.h"
#include "PredicateNode.h"
#include "Visitor.h"

void PredicateNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
