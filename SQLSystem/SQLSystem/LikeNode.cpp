#include "stdafx.h"
#include "LikeNode.h"
#include "Visitor.h"

void LikeNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
