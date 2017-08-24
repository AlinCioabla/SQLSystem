#pragma once
#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"

class AstTraversal
{
public:
  AstTraversal(const Ast & aAst)
    : mAst(aAst)
  {
    mCurrentNode = mAst.GetRoot();
  }

  AstNode * GetNextNode();
  void      ResetNext();

private:
  stack<AstNode *> stack;
  AstNode *        mCurrentNode;
  AstNode *        mReturnedToken;

  const Ast & mAst;
};
