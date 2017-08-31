#pragma once

#include "XmlNodeAttributes.h"

class WriterXml
{
public:
  WriterXml(ofstream & aFileName)
    : mOutputFile(aFileName)
    , indent(0)
  {
  }
  void Init();

  void ApplyIndentation(int aNumberOfSpaces);

  void AddNode(const string& aNodeName, int aLine, int aColumn, const string& aWord, bool aHasChildren);
  void CloseNode(const string& aNodeName, bool aHasChildren);
  ~WriterXml();

private:
  ofstream & mOutputFile;
  int        indent;
};
