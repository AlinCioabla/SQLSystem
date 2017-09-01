#pragma once
#include "Serializer.h"
#include "WriterXml.h"

class XmlRewriter : public Serializer
{
public:
  XmlRewriter(Ast & aAst, string aFilePath)
    : Serializer(aAst)
    , mXmlWr(aFilePath)
  {
  }
  void Serialize() override;

private:
  void                TraverseAst(AstNode * aNode);
  map<string, string> GetNodeAttr(AstNode * aNode);
  WriterXml           mXmlWr;
};
