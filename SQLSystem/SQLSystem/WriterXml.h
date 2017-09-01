#pragma once

#include "IBuffer.h"
#include "XmlNodeAttributes.h"

class WriterXml
{
public:
  WriterXml(string aFilePath)
    : mOutputStream(aFilePath)
    , indent(0)
  {
    Init(aFilePath);
  }
  WriterXml() = default;
  void Init(string aFilePath);

  void ApplyIndentation();

  void AddNode(
    const string & aNodeName, int aLine, int aColumn, const string & aWord, bool aHasChildren);
  void CloseNode(const string & aNodeName, bool aHasChildren);
  ~WriterXml();

private:
  ofstream  mOutputStream;
  int       indent;
  IBuffer * mBuffer;
};
