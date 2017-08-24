#pragma once
#include "ISerializer.h"
class ReWriterXml : public ISerializer
{
public:
  ReWriterXml(Ast & aAst)
    : mAst(aAst){};
  void Serialize() const override;
  virtual ~ReWriterXml() = default;

private:
  Ast & mAst;
};
