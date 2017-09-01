#pragma once

#include "XmlNodeAttributes.h"

class WriterXml
{
public:
  WriterXml(string aFilePath) { Init(aFilePath); }
  WriterXml();

  void Init(string aFilePath);

  void ApplyIndentation(int aNumberOfSpaces);

  void AddNode(string aNodeName, bool aHasChildren, map<string, string> Attr);

  void CloseNode();

  ~WriterXml();

private:
  ostream mOutputStream;
  int     indent;
};
