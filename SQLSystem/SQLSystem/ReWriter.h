#pragma once
#include "stdafx.h"
#include "Ast.h"
class ReWriter
{
public:
  ReWriter(Ast & aAst)
    : mAst(aAst){};

  void RewriteQuery();

  ~ReWriter();

private:
  Ast &  mAst;
  string mAstQuery;
};
