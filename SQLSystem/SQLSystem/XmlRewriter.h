#pragma once
#include "ISerializer.h"
class XmlRewriter : public ISerializer
{
public:
  XmlRewriter(Ast & aAst, string aFileName)
    : ISerializer(aAst, aFileName)
  {
  }
  void Serialize() override;

private:
  void TraverseAst(AstNode * aNode, int indent = 0);
};
