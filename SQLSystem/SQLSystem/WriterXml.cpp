#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

void WriterXml::Init()
{
}

void WriterXml::AddNode(
  string aNodeName, int aLine, int aColumn, string aType, string aWord, bool aHasChildren)
{
  mOutputFile << setw(indent) << "<" << aNodeName << R"( Line=")" << aLine << R"(" Column=")"
              << aColumn << R"(" Type=")" << aColumn << R"(")"
              << R"( Word=")" << aWord << R"(")";
  if (aHasChildren)
    mOutputFile << ">\n";

  indent += 3;
}

void WriterXml::CloseNode(
  string aNodeName, int aLine, int aColumn, string aType, string aWord, bool aHasChildren)
{
  if (aHasChildren)
    mOutputFile << setw(indent) << "</" << aNodeName << ">" << '\n';
  else

    mOutputFile << "/" << aNodeName << ">" << '\n';

  indent -= 3;
}

WriterXml::~WriterXml()
{
}
