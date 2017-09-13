#pragma once
#include "stdafx.h"
#include "Serializer.h"
class Writer
{
public:
  Writer(ofstream & aFileName)
    : mOutputStream(aFileName){};

 

protected:
  ofstream & mOutputStream;
};
