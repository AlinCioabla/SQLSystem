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

class NodeFactory
{
public:
  NodeFactory();
  AstNodePtr GetNode(string aNodeType, TokenPtr & aToken);
};
