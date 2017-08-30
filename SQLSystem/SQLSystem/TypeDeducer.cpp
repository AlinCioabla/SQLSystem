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
}

void TypeDeducer::Visit(ColumnNode & aColumnNode)
{
}

void TypeDeducer::Visit(CommaNode & aCommaNode)
{
}

void TypeDeducer::Visit(DistinctNode & aDistinctNode)
{
}

void TypeDeducer::Visit(DivisionOpNode & aDivisionOpNode)
{
}

void TypeDeducer::Visit(EqualsNode & aEqualsNode)
{
}

void TypeDeducer::Visit(FromNode & aFromNode)
{
}

void TypeDeducer::Visit(InsertNode & aInsertNode)
{
}

void TypeDeducer::Visit(IntoNode & aIntoNode)
{
}

void TypeDeducer::Visit(LikeNode & aLikeNode)
{
}

void TypeDeducer::Visit(MinusOpNode & aMinusOpNode)
{
}

void TypeDeducer::Visit(MultiplicationOpNode & aMultiplicationOpNode)
{
}

void TypeDeducer::Visit(NotLikeNode & aNotLikeNode)
{
}

void TypeDeducer::Visit(NumberNode & aNumberNode)
{
}

void TypeDeducer::Visit(OrNode & aOrNode)
{
}

void TypeDeducer::Visit(PlusOpNode & aPlusOpNode)
{
}

void TypeDeducer::Visit(PredicateNode & aPredicateNode)
{
}

void TypeDeducer::Visit(TableNode & aTableNode)
{
}

void TypeDeducer::Visit(UpdateNode & aUpdateNode)
{
}

void TypeDeducer::Visit(ValueNode & aValueNode)
{
}

void TypeDeducer::Visit(ValuesNode & aValuesNode)
{
}

void TypeDeducer::Visit(WhereNode & aWhereNode)
{
}
