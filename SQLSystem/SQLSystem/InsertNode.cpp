#include "stdafx.h"
#include "InsertNode.h"
#include "Visitor.h"

void InsertNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}

InsertNode::~InsertNode()
{
}
