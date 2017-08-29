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

  void AddNode(
    string aNodeName, int aLine, int aColumn, string aType, string aWord, bool aHasChildren);
  void CloseNode(
    string aNodeName, int aLine, int aColumn, string aType, string aWord, bool aHasChildren);
  ~WriterXml();

private:
  ofstream & mOutputFile;
  int        indent;
};
