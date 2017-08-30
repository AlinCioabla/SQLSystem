#include "stdafx.h"
#include "SelectNode.h"
#include "Visitor.h"

void SelectNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
