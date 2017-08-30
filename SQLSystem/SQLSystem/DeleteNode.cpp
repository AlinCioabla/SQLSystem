#include "stdafx.h"
#include "DeleteNode.h"
#include "Visitor.h"

void DeleteNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
