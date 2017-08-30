#pragma once
#include "AllNode.h"
#include "AndNode.h"
#include "AstNode.h"
#include "ColumnNode.h"
#include "CommaNode.h"
#include "DeleteNode.h"
#include "DistinctNode.h"
#include "DivisionOpNode.h"
#include "EqualsNode.h"
#include "FromNode.h"
#include "InsertNode.h"
#include "IntoNode.h"
#include "Invalid.h"
#include "InvalidNode.h"
#include "LikeNode.h"
#include "MinusOpNode.h"
#include "MultiplicationOpNode.h"
#include "NotLikeNode.h"
#include "NumberNode.h"
#include "OrNode.h"
#include "PlusOpNode.h"
#include "PredicateNode.h"
#include "SelectNode.h"
#include "TableNode.h"
#include "UpdateNode.h"
#include "ValueNode.h"
#include "ValuesNode.h"
#include "WhereNode.h"

class Visitor
{
public:
  virtual void Visit(SelectNode &)           = 0;
  virtual void Visit(DeleteNode &)           = 0;
  virtual void Visit(AllNode &)              = 0;
  virtual void Visit(AndNode &)              = 0;
  virtual void Visit(ColumnNode &)           = 0;
  virtual void Visit(CommaNode &)            = 0;
  virtual void Visit(DistinctNode &)         = 0;
  virtual void Visit(DivisionOpNode &)       = 0;
  virtual void Visit(EqualsNode &)           = 0;
  virtual void Visit(FromNode &)             = 0;
  virtual void Visit(InsertNode &)           = 0;
  virtual void Visit(IntoNode &)             = 0;
  virtual void Visit(LikeNode &)             = 0;
  virtual void Visit(MinusOpNode &)          = 0;
  virtual void Visit(MultiplicationOpNode &) = 0;
  virtual void Visit(NotLikeNode &)          = 0;
  virtual void Visit(NumberNode &)           = 0;
  virtual void Visit(OrNode &)               = 0;
  virtual void Visit(PlusOpNode &)           = 0;
  virtual void Visit(PredicateNode &)        = 0;
  virtual void Visit(TableNode &)            = 0;
  virtual void Visit(UpdateNode &)           = 0;
  virtual void Visit(ValueNode &)            = 0;
  virtual void Visit(ValuesNode &)           = 0;
  virtual void Visit(WhereNode &)            = 0;
  virtual void Visit(InvalidNode &)          = 0;
};
