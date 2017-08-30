#include "stdafx.h"
#include "FromNode.h"
#include "Visitor.h"

void FromNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
