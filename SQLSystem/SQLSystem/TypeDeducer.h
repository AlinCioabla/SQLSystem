#pragma once
#include "Visitor.h"

class TypeDeducer : public Visitor
{
public:
  TypeDeducer();

  void Visit(SelectNode & aSelectNode) override;
  void Visit(AndNode & aAndNode);
  void Visit(ColumnNode & aColumnNode);
  void Visit(CommaNode & aCommaNode);
  void Visit(DistinctNode & aDistinctNode);
  void Visit(DivisionOpNode & aDivisionOpNode);
  void Visit(EqualsNode & aEqualsNode);
  void Visit(FromNode & aFromNode);
  void Visit(InsertNode & aInsertNode);
  void Visit(IntoNode & aIntoNode);
  void Visit(LikeNode & aLikeNode);
  void Visit(MinusOpNode & aMinusOpNode);
  void Visit(MultiplicationOpNode & aMultiplicationOpNode);
  void Visit(NotLikeNode & aNotLikeNode);
  void Visit(NumberNode & aNumberNode);
  void Visit(OrNode & aOrNode);
  void Visit(PlusOpNode & aPlusOpNode);
  void Visit(PredicateNode & aPredicateNode);
  void Visit(TableNode & aTableNode);
  void Visit(UpdateNode & aUpdateNode);
  void Visit(ValueNode & aValueNode);
  void Visit(ValuesNode & aValuesNode);
  void Visit(WhereNode & aWhereNode);
  void Visit(InvalidNode & aInvalidNode);

  string GetOutput() const { return mOutput; }

private:
  string mOutput;
};
