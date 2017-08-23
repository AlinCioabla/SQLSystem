#pragma once
#include "stdafx.h"
#include "AstNode.h"
class ISerializer
{
public:
  ISerializer(){};
  virtual void DisplayAstInConsole(AstNode * aNode, int indent) const = 0;

  virtual ~ISerializer() = default;
};
