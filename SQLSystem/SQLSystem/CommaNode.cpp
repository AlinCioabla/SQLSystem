#include "stdafx.h"
#include "CommaNode.h"
#include "Visitor.h"

void CommaNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}
