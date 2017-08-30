#pragma once
#include "Visitor.h"

class TypeDeducer : public Visitor
{
public:
  void Visit(SelectNode & aSelectNode) override;
  void Visit(AndNode & aAndNode) override;
  void Visit(ColumnNode & aColumnNode) override;
  void Visit(CommaNode & aCommaNode) override;
  void Visit(DistinctNode & aDistinctNode) override;
  void Visit(DivisionOpNode & aDivisionOpNode) override;
  void Visit(EqualsNode & aEqualsNode) override;
  void Visit(FromNode & aFromNode) override;
  void Visit(InsertNode & aInsertNode) override;
  void Visit(IntoNode & aIntoNode) override;
  void Visit(LikeNode & aLikeNode) override;
  void Visit(MinusOpNode & aMinusOpNode) override;
  void Visit(MultiplicationOpNode & aMultiplicationOpNode) override;
  void Visit(NotLikeNode & aNotLikeNode) override;
  void Visit(NumberNode & aNumberNode) override;
  void Visit(OrNode & aOrNode) override;
  void Visit(PlusOpNode & aPlusOpNode) override;
  void Visit(PredicateNode & aPredicateNode) override;
  void Visit(TableNode & aTableNode) override;
  void Visit(UpdateNode & aUpdateNode) override;
  void Visit(ValueNode & aValueNode) override;
  void Visit(ValuesNode & aValuesNode) override;
  void Visit(WhereNode & aWhereNode) override;
  void Visit(InvalidNode & aInvalidNode) override;

  string GetOutput() const { return mOutput; }

private:
  string mOutput;
};
