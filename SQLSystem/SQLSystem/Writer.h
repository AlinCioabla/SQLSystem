#pragma once
#include "stdafx.h"
#include "Serializer.h"
class Writer
{
public:
  Writer(ofstream & aFileName)
    : mOutputStream(aFileName){};

  virtual ~Writer() = default;

protected:
  ofstream & mOutputStream;
};
