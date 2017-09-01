#pragma once
#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"
#include "AstTraversal.h"
class Serializer
{
public:
  Serializer(const Ast & aAst)
    : mAst(aAst)
  {
  }
  virtual void Serialize() = 0;

  virtual ~Serializer() = default;

protected:
  const Ast & mAst;
};
