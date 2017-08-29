#pragma once
#include "stdafx.h"
#include "Ast.h"
#include "Serializer.h"
class TextRewriter : public Serializer
{
public:
  TextRewriter(const Ast & aAst, string aFileName)
    : Serializer(aAst, aFileName)
  {
  }

  void Serialize() override;

  void DisplayAstInConsole(AstNode * aNode, int indent) const;

  string GetQuery() const;

private:
  void TraverseTree(AstNode * aNode, string & aAstQuery) const;
};
