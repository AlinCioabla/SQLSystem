#include "stdafx.h"
#include "BufferXml.h"

void BufferXml::Update(string aCommand)
{
  mBufferString += aCommand;
}

string BufferXml::Get()
{
  return mBufferString;
}

void BufferXml::Clear()
{
  mBufferString = "";
}
