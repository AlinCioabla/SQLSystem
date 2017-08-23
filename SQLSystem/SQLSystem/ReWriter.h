#pragma once
#include "stdafx.h"
#include "Ast.h"
class ReWriter
{
public:
  ReWriter(const Ast & aAst)
    : mAst(aAst){};

  void DisplayAstInConsole(AstNode * aNode, int indent) const;

  string GetQuery() const;

private:
  void        RewriteQuery(AstNode * aNode, string & aAstQuery) const;
  const Ast & mAst;
};
