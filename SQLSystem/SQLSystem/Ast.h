#pragma once
#include "AstNode.h"

class Ast
{
public:
  Ast(AstNode * aRoot)
    : mRoot(aRoot){};

  AstNode * NewNode(IToken * aToken);
  AstNode * InsertNode(AstNode * aNode, IToken * aToken);

  void      Display(AstNode * current, int indent);
  AstNode * GetRoot() const { return mRoot; };

  ~Ast();  // must implement
private:
  AstNode * mRoot;
};
