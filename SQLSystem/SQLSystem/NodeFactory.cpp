#include "stdafx.h"
#include "NodeFactory.h"
#include "AllNode.h"
#include "AndNode.h"
#include "Ast.h"
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
#include "Undefined.h"
#include "UpdateNode.h"
#include "ValueNode.h"
#include "ValuesNode.h"
#include "WhereNode.h"

AstNodePtr NodeFactory::GetNode(string aNodeType, TokenPtr & aToken)
{
  if (aNodeType == "select")
    return make_shared<SelectNode>(move(aToken));

  if (aNodeType == "all")
    return make_shared<AllNode>(move(aToken));

  if (aNodeType == "delete")
    return make_shared<DeleteNode>(move(aToken));

  if (aNodeType == "and")
    return make_shared<AndNode>(move(aToken));

  if (aNodeType == "column")
    return make_shared<ColumnNode>(move(aToken));

  if (aNodeType == "comma")
    return make_shared<CommaNode>(move(aToken));

  if (aNodeType == "distinct")
    return make_shared<DistinctNode>(move(aToken));

  if (aNodeType == "divisionop")
    return make_shared<DivisionOpNode>(move(aToken));

  if (aNodeType == "equals")
    return make_shared<EqualsNode>(move(aToken));

  if (aNodeType == "from")
    return make_shared<FromNode>(move(aToken));

  if (aNodeType == "insert")
    return make_shared<InsertNode>(move(aToken));

  if (aNodeType == "into")
    return make_shared<IntoNode>(move(aToken));

  if (aNodeType == "like")
    return make_shared<LikeNode>(move(aToken));

  if (aNodeType == "minusop")
    return make_shared<MinusOpNode>(move(aToken));

  if (aNodeType == "multiplicationop")
    return make_shared<MultiplicationOpNode>(move(aToken));

  if (aNodeType == "notlike")
    return make_shared<NotLikeNode>(move(aToken));

  if (aNodeType == "number")
    return make_shared<NumberNode>(move(aToken));

  if (aNodeType == "or")
    return make_shared<OrNode>(move(aToken));

  if (aNodeType == "plusop")
    return make_shared<PlusOpNode>(move(aToken));

  if (aNodeType == "predicate")
    return make_shared<PredicateNode>(move(aToken));

  if (aNodeType == "table")
    return make_shared<TableNode>(move(aToken));

  if (aNodeType == "update")
    return make_shared<UpdateNode>(move(aToken));

  if (aNodeType == "value")
    return make_shared<ValueNode>(move(aToken));

  if (aNodeType == "values")
    return make_shared<ValuesNode>(move(aToken));

  if (aNodeType == "where")
    return make_shared<WhereNode>(move(aToken));

  if (aNodeType == "invalid")
    return make_shared<InvalidNode>(move(aToken));

  return nullptr;
}
