#include "stdafx.h"
#include "BufferXml.h"

void BufferXml::Update(string aCommand)
{
  *this << aCommand;
}


void BufferXml::Clear()
{
  mBufferString = "";
}

string BufferXml::Get()
{
	return mBufferString;
}
