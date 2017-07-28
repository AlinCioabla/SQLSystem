#pragma once
#include "AstNode.h"

class Ast
{
public:
  Ast(AstNode * aRoot)
    : mRoot(aRoot){};
  Ast(const Ast & aAst);

  Ast();

  void Display(AstNodePtr aNode, int indent) const;

  void PrintQuery(AstNodePtr aNode);

  void SetRoot(AstNodePtr aNode);

  AstNodePtr GetRoot() const { return mRoot; };

  static AstNodePtr GetNewNode(TokenPtr aTokenPtr) { return make_shared<AstNode>(aTokenPtr); }

  ~Ast();

private:
  AstNodePtr mRoot;
};
