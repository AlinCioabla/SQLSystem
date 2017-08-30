#include "stdafx.h"
#include "NodeFactory.h"

NodeFactory::NodeFactory()
{
}

AstNodePtr NodeFactory::GetNode(string aNodeType, TokenPtr & aToken)
{
  if (aNodeType == "select")
    return make_shared<SelectNode>(aToken);

  if (aNodeType == "and")
    return make_shared<AndNode>(aToken);

  if (aNodeType == "column")
    return make_shared<ColumnNode>(aToken);

  if (aNodeType == "comma")
    return make_shared<CommaNode>(aToken);

  if (aNodeType == "distinct")
    return make_shared<DistinctNode>(aToken);

  if (aNodeType == "divisionop")
    return make_shared<DivisionOpNode>(aToken);

  if (aNodeType == "equals")
    return make_shared<EqualsNode>(aToken);

  if (aNodeType == "from")
    return make_shared<FromNode>(aToken);

  if (aNodeType == "insert")
    return make_shared<InsertNode>(aToken);

  if (aNodeType == "into")
    return make_shared<IntoNode>(aToken);

  if (aNodeType == "like")
    return make_shared<LikeNode>(aToken);

  if (aNodeType == "minusop")
    return make_shared<MinusOpNode>(aToken);

  if (aNodeType == "multiplicationop")
    return make_shared<MultiplicationOpNode>(aToken);

  if (aNodeType == "notlike")
    return make_shared<NotLikeNode>(aToken);

  if (aNodeType == "number")
    return make_shared<NumberNode>(aToken);

  if (aNodeType == "or")
    return make_shared<OrNode>(aToken);

  if (aNodeType == "plusop")
    return make_shared<PlusOpNode>(aToken);

  if (aNodeType == "predicate")
    return make_shared<PredicateNode>(aToken);

  if (aNodeType == "table")
    return make_shared<TableNode>(aToken);

  if (aNodeType == "update")
    return make_shared<UpdateNode>(aToken);

  if (aNodeType == "value")
    return make_shared<ValueNode>(aToken);

  if (aNodeType == "values")
    return make_shared<ValuesNode>(aToken);

  if (aNodeType == "where")
    return make_shared<WhereNode>(aToken);

  return nullptr;
}
