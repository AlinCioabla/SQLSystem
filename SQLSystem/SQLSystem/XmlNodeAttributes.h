#pragma once
#include "stdafx.h"

class XmlNodeAttributes
{
public:
  XmlNodeAttributes(
    string aNodeName, int aLine, int aColumn, string aType, string aWord, bool aHasChildren)
    : mNodeName(aNodeName)
    , mLine(aLine)
    , mColumn(aColumn)
    , mType(aType)
    , mWord(aWord)
    , mHasChildren(aHasChildren)
  {
  }

  string GetName() const { return mNodeName; }
  int    GetLine() const { return mLine; }
  int    GetColumn() const { return mColumn; }
  string GetType() const { return mType; }
  string GetWord() const { return mWord; }
  bool   HasChildren() const { return mHasChildren; }

  ~XmlNodeAttributes();

private:
  const string mNodeName;
  const int    mLine;
  const int    mColumn;
  const string mType;
  const string mWord;
  const bool   mHasChildren;
};
