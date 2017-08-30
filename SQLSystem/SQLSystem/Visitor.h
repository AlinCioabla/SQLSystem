#pragma once
#include "AstNode.h"
#include "SelectNode.h"

class Visitor
{
public:
  Visitor();
  virtual void Visit(SelectNode &) = 0;
  virtual void Visit()
};
