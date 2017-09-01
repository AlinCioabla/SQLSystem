#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

void WriterXml::ApplyIndentation()
{
  for (int i = 0; i < mCurrentIndent; i++)
  {
    // mBuffer.Update(mIndentChar);
  }
}

void WriterXml::StartDocument()
{
  // mBuffer.Update(R"(<?xml version="1.0" encoding="UTF-8"?>)");
  // mBuffer.Update("\n");

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

void WriterXml::AddNode(const string                aNodeName,
                        bool                        aHasChildren,
                        const map<string, string> & aAttr)
{
  if (!mDocStarted)
    return;

  ApplyIndentation();

  // mBuffer.Update("<" + aNodeName + " ");

  for (auto & attr : aAttr)
  {
    // mBuffer.Update(attr.first + "=" + attr.second);
    if (!aAttr.empty() && attr != *(prev(aAttr.end())))
    {
      // mBuffer.Update(" ");
    }
  }

  if (aHasChildren)
  {
    //  mBuffer.Update(">\n");
  }
  else
  {
    mNodes.push(aNodeName);
  }

  mCurrentIndent += mAddedIndent;
}

void WriterXml::CloseNode()
{
  if (!mDocStarted)
    return;

  mCurrentIndent -= mAddedIndent;
  /*if (aHasChildren)
  {
    ApplyIndentation();
    mOutputStream << "</" << aNodeName << ">"
                  << "\n";
  }
  else
  {
    mOutputStream << "/"
                  << ">"
                  << "\n";
  }*/
}

void WriterXml::Write()
{
}

void WriterXml::EndDocument()
{
  // mBuffer.Update("\n\n");
  mDocStarted = false;
}

WriterXml::~WriterXml() = default;
