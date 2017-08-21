#pragma once
#include "stdafx.h"
#include "Ast.h"
class ReWriter
{
public:
  ReWriter(Ast & aAst)
    : mAst(aAst){};

  void RewriteQuery(AstNode * aNode);

  void DisplayAstInConsole(AstNode * aNode, int indent) const;

  string GetQuery();

  Ast & GetAst() { return mAst; }

  ~ReWriter();

private:
  Ast &  mAst;
  string mAstQuery;
};
