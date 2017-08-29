#pragma once
#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"
#include "AstTraversal.h"
class Serializer
{
public:
  Serializer(const Ast & aAst, string aFileName)
    : mAst(aAst)
    , mOutputStream(aFileName, ios::out | ios::app | ios::ate)
  {
  }
  virtual void Serialize() = 0;

  virtual ~Serializer() = default;

protected:
  ofstream    mOutputStream;
  const Ast & mAst;
};
