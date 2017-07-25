#pragma once
#include "AstNode.h"

class Ast
{
public:
  Ast(AstNode * aRoot)
    : mRoot(aRoot){};

  AstNode * NewNode(IToken * aToken);
  AstNode * InsertNode(AstNode * aNode, IToken * aToken);

  void      Display(AstNode * aNode, int indent);
  void      PrintQuery(AstNode * aNode);
  AstNode * GetRoot() const { return mRoot; };

  ~Ast();  // must implement
private:
  AstNode * mRoot;
};
