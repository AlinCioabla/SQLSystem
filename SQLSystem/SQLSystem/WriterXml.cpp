#include "stdafx.h"
#include "WriterXml.h"
#include "Writer.h"

void WriterXml::AddNode(
  string aNodeName, bool aHasChildren, int aLine, int aColumn, string aType, string aWord)
{
  mOutputStream << setw(indent) << "<" << aNodeName << R"(  Line=")" << aLine << R"(" Column=")"
                << aColumn << R"(" Type=")" << aType << R"(")"
                << R"( Word=")" << aWord << R"(")"
                << ">";

  if (aHasChildren)
  {
    mOutputStream << "\n";
  }
  if (aHasChildren)
  {
    mOutputStream << setw(indent) << "</" << aNodeName << ">\n";
  }
  else
  {
    mOutputStream << "</" << aNodeName << ">\n";
  }
}

WriterXml::~WriterXml()
{
}
