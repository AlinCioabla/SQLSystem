#pragma once

#include "IBuffer.h"
#include "BufferXml.h"
#include "XmlNodeAttributes.h"

class WriterXml
{
public:
  WriterXml(string aFilePath = "", string aIndentChar = " "s)
    : mOutputStream(aFilePath, ios::app | ios::ate)
    , mIndentChar(aIndentChar)
    , mCurrentIndent(0)
  {
  }

  void StartDocument();

  void ReInit(string aFilePath = "", string aIndentChar = " "s);

  void AddNode(const string aNodeName, bool aHasChildren, const vector<pair<string, string>> & aAttr);

  void CloseNode();

  void Write();

  void EndDocument();
 

private:
  ofstream mOutputStream;
  string   mIndentChar;
  int      mCurrentIndent;

  BufferXml     mBuffer;
  stack<string> mNodes;

  
  void ApplyIndentation();

  bool mDocStarted = false;
};
