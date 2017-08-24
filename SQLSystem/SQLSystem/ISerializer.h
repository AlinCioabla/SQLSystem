#pragma once
#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"
class ISerializer
{
public:
  // virtual void Serialize() const = 0;

  virtual ~ISerializer() = default;
};
