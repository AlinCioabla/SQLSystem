#pragma once
#include "ISerializer.h"
class ReWriterXml : public ISerializer
{
public:
  ReWriterXml(Ast & aAst, string aFileName)
    : ISerializer(aAst, aFileName)
  {
  }
  void Serialize() const override;

private:
  void TraverseAst(AstNode * aNode, int indent = 0) const;
};
