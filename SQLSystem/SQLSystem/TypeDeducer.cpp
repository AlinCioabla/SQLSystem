#include "stdafx.h"
#include "TypeDeducer.h"

TypeDeducer::TypeDeducer()
{
}

void TypeDeducer::Visit(SelectNode & aSelectNode)
{
  mOutput = "SELECT";
}

void TypeDeducer::Visit(AndNode & aAndNode)
{
  mOutput = "AND";
}

void TypeDeducer::Visit(ColumnNode & aColumnNode)
{
  mOutput = "COLUMN";
}

void TypeDeducer::Visit(CommaNode & aCommaNode)
{
  mOutput = "COMMA";
}

void TypeDeducer::Visit(DistinctNode & aDistinctNode)
{
  mOutput = "DISTINCT";
}

void TypeDeducer::Visit(DivisionOpNode & aDivisionOpNode)
{
  mOutput = "DIVISIONOP";
}

void TypeDeducer::Visit(EqualsNode & aEqualsNode)
{
  mOutput = "EQUALS";
}

void TypeDeducer::Visit(FromNode & aFromNode)
{
  mOutput = "FROM";
}

void TypeDeducer::Visit(InsertNode & aInsertNode)
{
  mOutput = "INSERT";
}

void TypeDeducer::Visit(IntoNode & aIntoNode)
{
  mOutput = "INTO";
}

void TypeDeducer::Visit(LikeNode & aLikeNode)
{
  mOutput = "LIKE";
}

void TypeDeducer::Visit(MinusOpNode & aMinusOpNode)
{
  mOutput = "MINUSOP";
}

void TypeDeducer::Visit(MultiplicationOpNode & aMultiplicationOpNode)
{
  mOutput = "MULTIPLICATIONOP";
}

void TypeDeducer::Visit(NotLikeNode & aNotLikeNode)
{
  mOutput = "NOTLIKE";
}

void TypeDeducer::Visit(NumberNode & aNumberNode)
{
  mOutput = "NUMBER";
}

void TypeDeducer::Visit(OrNode & aOrNode)
{
  mOutput = "OR";
}

void TypeDeducer::Visit(PlusOpNode & aPlusOpNode)
{
  mOutput = "PLUSOP";
}

void TypeDeducer::Visit(PredicateNode & aPredicateNode)
{
  mOutput = "PREDICATE";
}

void TypeDeducer::Visit(TableNode & aTableNode)
{
  mOutput = "TABLE";
}

void TypeDeducer::Visit(UpdateNode & aUpdateNode)
{
  mOutput = "UPDATE";
}

void TypeDeducer::Visit(ValueNode & aValueNode)
{
  mOutput = "VALUE";
}

void TypeDeducer::Visit(ValuesNode & aValuesNode)
{
  mOutput = "VALUES";
}

void TypeDeducer::Visit(WhereNode & aWhereNode)
{
  mOutput = "WHERE";
}

void TypeDeducer::Visit(InvalidNode & aInvalidNode)
{
  mOutput = "INVALID";
}
