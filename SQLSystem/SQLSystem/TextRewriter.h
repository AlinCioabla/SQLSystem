#pragma once
#include "stdafx.h"
#include "ISerializer.h"
#include "Ast.h"
class TextRewriter : public ISerializer
{
public:
  TextRewriter(const Ast & aAst, string aFileName)
    : ISerializer(aAst, aFileName)
  {
  }

  void Serialize() override;

  void DisplayAstInConsole(AstNode * aNode, int indent) const;

  string GetQuery() const;

private:
  void TraverseTree(AstNode * aNode, string & aAstQuery) const;
};
