#pragma once

#include "IBuffer.h"
#include "BufferXml.h"
#include "XmlNodeAttributes.h"

class WriterXml
{
public:
  WriterXml(string aFilePath = "", string aIndentChar = " "s, int aAddedIndent = 3)
    : mOutputStream(aFilePath, ios::app | ios::ate)
    , mIndentChar(aIndentChar)
    , mAddedIndent(aAddedIndent)
    , mCurrentIndent(0)
  {
  }

  void StartDocument();

  void ReInit(string aFilePath = "", string aIndentChar = " "s, int aAddedIndent = 3);

  void AddNode(const string aNodeName, bool aHasChildren, const map<string, string> & aAttr);

  void CloseNode();

  void Write();

  void EndDocument();
  //ostream& operator<< (std::ostream &out, const Writer &point);

  ~WriterXml();

private:
  ofstream mOutputStream;
  string   mIndentChar;
  int      mAddedIndent;
  int      mCurrentIndent;

  BufferXml     mBuffer;
  stack<string> mNodes;

  
  void ApplyIndentation();

  bool mDocStarted = false;
};
