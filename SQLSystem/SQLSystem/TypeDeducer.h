#pragma once
#include "Visitor.h"

class TypeDeducer : public Visitor
{
public:
  TypeDeducer();

  void Visit(SelectNode & aSelectNode) override;

  string GetOutput() const { return mOutput; }

private:
  string mOutput;
};
