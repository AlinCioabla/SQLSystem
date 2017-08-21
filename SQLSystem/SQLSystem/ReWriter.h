#pragma once
#include "stdafx.h"
#include "Ast.h"
class ReWriter
{
public:
  ReWriter(Ast aAst)
    : mAst(aAst){};
  ~ReWriter();

private:
  Ast mAst;
};
