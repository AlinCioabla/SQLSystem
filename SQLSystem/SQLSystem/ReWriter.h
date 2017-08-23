#pragma once
#include "stdafx.h"
#include "ISerializer.h"
#include "Ast.h"
class ReWriter : public ISerializer
{
public:
  ReWriter(Ast & aAst)
    : mAst(aAst){};

  void DisplayAstInConsole(AstNode * aNode, int indent) const override;

  string GetQuery();

  Ast & GetAst() { return mAst; }

  ~ReWriter();

private:
  void  RewriteQuery(AstNode * aNode, string & aAstQuery);
  Ast & mAst;
};
