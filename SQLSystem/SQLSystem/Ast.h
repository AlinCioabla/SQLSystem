#pragma once
#include "AstNode.h"

class Ast
{
public:
  Ast(AstNode * aRoot)
    : mRoot(aRoot){};
  Ast(const Ast & aAst);

  Ast();

  void      Display(AstNode * aNode, int indent) const;
  void      PrintQuery(AstNode * aNode);
  void      SetRoot(AstNode * aNode);
  AstNode * GetRoot() const { return mRoot; };

  ~Ast();  // must implement
private:
  AstNode * mRoot;
};
