#pragma once
#include "ISerializer.h"
class ReWriterXml : public ISerializer
{
public:
  ReWriterXml(Ast & aAst, string aFileName)
    : mAst(aAst)
    , mOutputStream(aFileName, ios::out | ios::ate | ios::app){};
  void Serialize() const override;
  virtual ~ReWriterXml() = default;

private:
  ofstream mOutputStream;
  Ast &    mAst;
};
