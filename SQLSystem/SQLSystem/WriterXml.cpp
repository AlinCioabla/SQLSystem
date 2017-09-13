#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"
#include"BufferXml.h"

void WriterXml::ApplyIndentation()
{
  for (int i = 0; i < mCurrentIndent; i++)
  {
    mBuffer.Update(mIndentChar);
  }
}

void WriterXml::StartDocument()
{
  mBuffer.Update(R"(<?xml version="1.0" encoding="UTF-8"?>)");
  mBuffer.Update("\n");

  mDocStarted = true;
}

void WriterXml::ReInit(string aFilePath, string aIndentChar)
{
  mOutputStream.open(aFilePath);
  mIndentChar  = aIndentChar;
  mBuffer.Clear();
  mDocStarted = false;
}



void WriterXml::AddNode(const string                aNodeName,
                        bool                        aHasChildren,
                        const vector<pair<string, string>> & aAttr)
{
  if (!mDocStarted)
    return;
//------------
  ApplyIndentation();

  mBuffer.Update("<" + aNodeName + " ");

  for (auto & attr : aAttr)
  {
    mBuffer.Update(attr.first + "=" + "\"" + attr.second + "\"");
    if (!aAttr.empty() && attr != *(prev(aAttr.end())))
    {
      mBuffer.Update(" ");
    }
  }

  if (aHasChildren)
  {
    mBuffer <<  mCurrentIndent << ">\n" << aHasChildren;

    mNodes.push(aNodeName);
    mCurrentIndent = mNodes.size()*3;
  }
  else
  {
    mBuffer.Update("/>\n");
  }
}

void WriterXml::CloseNode()
{
	if (!mDocStarted) {
		return;
	}
  ApplyIndentation();

  mBuffer.Update("</"s + mNodes.top() + ">\n"s);
  mNodes.pop();
 
  mCurrentIndent = (mNodes.size() - 1) * 3;
}

void WriterXml::Write()
{
  if (mOutputStream)
    mOutputStream << mBuffer.Get();
}

void WriterXml::EndDocument()
{
  mBuffer.Update("\n\n");
  mDocStarted = false;
}

