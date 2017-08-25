#pragma once
#include "ISerializer.h"
class ReWriterXml : public ISerializer
{
public:
  ReWriterXml(Ast & aAst, string aFileName)
    : ISerializer(aAst, aFileName)
  {
    mOutputStream.open(aFileName, ios::out | ios::ate | ios::app);
  }
  void Serialize() override;

private:
  void TraverseAst(AstNode * aNode, int indent = 0);
};
