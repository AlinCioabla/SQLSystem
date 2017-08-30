#include "stdafx.h"
#include "NotLikeNode.h"
#include "Visitor.h"

void NotLikeNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
