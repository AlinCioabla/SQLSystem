#pragma once
#include "stdafx.h"
#include "Serializer.h"
class Writer
{
public:
  Writer(ofstream & aFileName)
    : mOutputStream(aFileName){};
  virtual void AddNode(
    string aNodeName, bool aHasChildren, int aLine, int aColumn, string aType, string aWord) = 0;
  virtual ~Writer() = default;

private:
  ofstream & mOutputStream;
};
