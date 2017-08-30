#include "stdafx.h"
#include "NumberNode.h"
#include "Visitor.h"

void NumberNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
