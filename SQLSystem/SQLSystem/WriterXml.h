#pragma once
#include "Writer.h"
class WriterXml : public Writer
{
public:
  WriterXml();
  void AddNode(string aNodeName,
               bool   aHasChildren,
               int    aLine,
               int    aColumn,
               string aType,
               string aWord) override;
  ~WriterXml();
};
