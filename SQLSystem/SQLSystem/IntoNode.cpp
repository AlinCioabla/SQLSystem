#include "stdafx.h"
#include "IntoNode.h"
#include "Visitor.h"

void IntoNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
