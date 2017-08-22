#pragma once
#include "stdafx.h"
#include "Ast.h"
class ReWriter
{
public:
  ReWriter(Ast & aAst)
    : mAst(aAst){};

  void DisplayAstInConsole(AstNode * aNode, int indent) const;

  string GetQuery();

  Ast & GetAst() { return mAst; }

  ~ReWriter();

private:
  void   RewriteQuery(AstNode * aNode);
  Ast &  mAst;
  string mAstQuery;
};
