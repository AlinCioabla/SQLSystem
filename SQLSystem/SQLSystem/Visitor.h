#pragma once
#include "AllNode.h"
#include "AndNode.h"
#include "AstNode.h"
#include "ColumnNode.h"
#include "DistinctNode.h"
#include "FromNode.h"
#include "LikeNode.h"
#include "MultiplicationOpNode.h"
#include "NotLikeNode.h"
#include "SelectNode.h"
#include "TableNode.h"
#include "UpdateNode.h"
#include

class Visitor
{
public:
  Visitor();
  virtual void Visit(SelectNode &) = 0;
  virtual void Visit()
};
