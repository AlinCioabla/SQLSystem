#pragma once
#include "ISerializer.h"
class ReWriterXml : public ISerializer
{
public:
  ReWriterXml(Ast & aAst, string aFileName, AstTraversal & aAstTraversal)
    : ISerializer(aAst, aFileName, aAstTraversal)
  {
  }
  void Serialize() const override;
};
