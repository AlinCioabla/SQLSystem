#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

void WriterXml::Init()
{
  mOutputFile << R"(<?xml version="1.0" encoding="UTF-8"?>)"
              << "\n";
}

void WriterXml::ApplyIndentation(int aNumberOfSpaces)
{
  for (int i = 0; i < aNumberOfSpaces; i++)
  {
    mOutputFile << " ";
  }
}

void WriterXml::AddNode(
  const string & aNodeName, int aLine, int aColumn, const string & aWord, bool aHasChildren)
{
  ApplyIndentation(indent);
  mOutputFile << "<" << aNodeName << R"( Line=")" << aLine << R"(" Column=")" << aColumn << R"(")"
              << R"( Word=")" << aWord << R"(")";
  if (aHasChildren)
  {
    mOutputFile << ">\n";
  }

  indent += 3;
}

void WriterXml::CloseNode(const string & aNodeName, bool aHasChildren)
{
  indent -= 3;
  if (aHasChildren)
  {
    ApplyIndentation(indent);
    mOutputFile << "</" << aNodeName << ">"
                << "\n";
  }
  else
  {
    mOutputFile << "/"
                << ">"
                << "\n";
  }
}

WriterXml::~WriterXml() = default;
