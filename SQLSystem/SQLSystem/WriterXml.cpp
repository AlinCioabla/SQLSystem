#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

void WriterXml::Init(string aFilePath)

{
  mBuffer->Update(R"(<?xml version="1.0" encoding="UTF-8"?>)");
  mBuffer->Update("\n");
}

void WriterXml::ApplyIndentation()
{
  for (int i = 0; i < aNumberOfSpaces; i++)
  {
    mBuffer->Update(" ");
  }
}

void WriterXml::AddNode(
  const string & aNodeName, int aLine, int aColumn, const string & aWord, bool aHasChildren)
{
  ApplyIndentation(indent);
  mBuffer->Update("<" + aNodeName + (R"( Line=")"));
  mBuffer->Update(aLine);
  mBuffer->Update(R"(" Column=")");
  mBuffer->Update(aColumn);
  mBuffer->Update(R"(")"
                  R"( Word=")" +
                  aWord + R"(")");
  if (aHasChildren)
  {
    mOutputStream << ">\n";
  }

  indent += 3;
}

void WriterXml::CloseNode(const string & aNodeName, bool aHasChildren)
{
  indent -= 3;
  if (aHasChildren)
  {
    ApplyIndentation(indent);
    mOutputStream << "</" << aNodeName << ">"
                  << "\n";
  }
  else
  {
    mOutputStream << "/"
                  << ">"
                  << "\n";
  }
}

WriterXml::~WriterXml() = default;
