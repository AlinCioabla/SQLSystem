#pragma once
#include "Serializer.h"
#include "WriterXml.h"

class XmlRewriter : public Serializer
{
public:
  XmlRewriter(Ast & aAst, string aFileName)
    : Serializer(aAst, aFileName)
    , mXmlWr(mOutputStream)
  {
  }
  void Serialize() override;

private:
  void      TraverseAst(AstNode * aNode);
  WriterXml mXmlWr;
};
