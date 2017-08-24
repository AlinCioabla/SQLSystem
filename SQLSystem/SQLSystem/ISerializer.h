#pragma once
#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"
#include "AstTraversal.h"
class ISerializer
{
public:
  ISerializer(Ast & aAst, string aFileName)
    : mAst(aAst)
    , mOutputStream(aFileName){};

  virtual void Serialize() = 0;

  virtual ~ISerializer() = default;

protected:
  ofstream mOutputStream;
  Ast &    mAst;
};
