#include "stdafx.h"
#include "TableNode.h"
#include "Visitor.h"

void TableNode::Accept(Visitor & aVisitor)
{
  aVisitor.Visit(*this);
}

TableNode::~TableNode()
{
}
