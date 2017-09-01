#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

void WriterXml::Init(string aFilePath)

{
  mOutputStream << R"(<?xml version="1.0" encoding="UTF-8"?>)"
                << "\n";
}

void WriterXml::ApplyIndentation()
{
  for (int i = 0; i < aNumberOfSpaces; i++)
  {
    mOutputStream << " ";
  }
}

void WriterXml::AddNode(
  const string & aNodeName, int aLine, int aColumn, const string & aWord, bool aHasChildren)
{
  ApplyIndentation(indent);
  mOutputStream << "<" << aNodeName << R"( Line=")" << aLine << R"(" Column=")" << aColumn << R"(")"
                << R"( Word=")" << aWord << R"(")";
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
