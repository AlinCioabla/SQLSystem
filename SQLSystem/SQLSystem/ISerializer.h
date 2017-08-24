#pragma once
#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"
#include "AstTraversal.h"
class ISerializer
{
public:
  ISerializer(Ast & aAst, string aFileName, AstTraversal & aAstTraversal)
    : mAst(aAst)
    , mAstTraversal(aAstTraversal)
  {
    mOutputStream.open(aFileName, ios::out | ios::ate | ios::app);
  };

  virtual void Serialize() const = 0;

  virtual ~ISerializer() = default;

protected:
  ofstream       mOutputStream;
  Ast &          mAst;
  AstTraversal & mAstTraversal;
};
