#include "stdafx.h"
#include "UpdateNode.h"
#include "Visitor.h"

void UpdateNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
