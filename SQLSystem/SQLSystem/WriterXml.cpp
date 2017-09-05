#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

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

void WriterXml::ReInit(string aFilePath, string aIndentChar, int aAddedIndent)
{
  mOutputStream.open(aFilePath);
  mIndentChar  = aIndentChar;
  mAddedIndent = aAddedIndent;
  mBuffer.Clear();
  mDocStarted = false;
}

string to_string(const Gogu & g)
{
  return g.AsStr();
}

void WriterXml::AddNode(const string                aNodeName,
                        bool                        aHasChildren,
                        const map<string, string> & aAttr)
{
  if (!mDocStarted)
    return;

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
    mBuffer << 5L << gogu << mCurrentIndent << ">\n" << aHasChildren;

    mNodes.push(aNodeName);
    mCurrentIndent += mAddedIndent;
  }
  else
  {
    mBuffer.Update("/>\n");
  }
}

void WriterXml::CloseNode()
{
  if (!mDocStarted)
    return;

  mCurrentIndent -= mAddedIndent;
  ApplyIndentation();

  mBuffer.Update("</"s + mNodes.top() + ">\n"s);
  mNodes.pop();
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

WriterXml::~WriterXml() = default;
