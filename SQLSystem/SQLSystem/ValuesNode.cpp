#include "stdafx.h"
#include "ValuesNode.h"
#include "Visitor.h"

void ValuesNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}

ValuesNode::~ValuesNode()
{
}
