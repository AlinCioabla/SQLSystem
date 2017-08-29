#pragma once
#include "stdafx.h"

class XmlNodeAttributes
{
public:
  XmlNodeAttributes(string aNodeName, int aLine, int aColumn, string aType, string aWord)
    : mNodeName(aNodeName)
    , mLine(aLine)
    , mColumn(aColumn)
    , mType(aType)
    , mWord(aWord){};

  ~XmlNodeAttributes();

private:
  string mNodeName;
  int    mLine;
  int    mColumn;
  string mType;
  string mWord;
};
