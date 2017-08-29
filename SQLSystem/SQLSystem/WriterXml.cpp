#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

void WriterXml::Init()
{
}

void WriterXml::ApplyIndentation(int aNumberOfSpaces)
{
  for (int i = 0; i < aNumberOfSpaces; i++)
  {
    mOutputFile << " ";
  }
}

void WriterXml::AddNode(
  string aNodeName, int aLine, int aColumn, string aType, string aWord, bool aHasChildren)
{
  ApplyIndentation(indent);
  mOutputFile << "<" << aNodeName << R"( Line=")" << aLine << R"(" Column=")" << aColumn
              << R"(" Type=")" << aType << R"(")"
              << R"( Word=")" << aWord << R"(")";
  if (aHasChildren)
  {
    mOutputFile << ">\n";
  }

  indent += 3;
}

void WriterXml::CloseNode(
  string aNodeName, int aLine, int aColumn, string aType, string aWord, bool aHasChildren)
{
  indent -= 3;
  if (aHasChildren)
  {
    ApplyIndentation(indent);
    mOutputFile << "</" << aNodeName << ">"
                << "\n";
  }
  else
    mOutputFile << "/"
                << ">"
                << "\n";
}

WriterXml::~WriterXml()
{
}
