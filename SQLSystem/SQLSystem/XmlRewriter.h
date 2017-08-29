#pragma once
#include "Serializer.h"
class XmlRewriter : public Serializer
{
public:
  XmlRewriter(Ast & aAst, string aFileName)
    : Serializer(aAst, aFileName)
  {
    mXmlWr(mOutputStream);
  }
  void Serialize() override;

private:
  void      TraverseAst(AstNode * aNode, int indent = 0);
  WriterXml mXmlWr;
};
