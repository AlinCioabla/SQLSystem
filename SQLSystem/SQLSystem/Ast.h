#pragma once
#include "AstNode.h"

class Ast
{
public:
  Ast(AstNodePtr aRoot)
    : mRoot(aRoot){};
  Ast(const Ast & aAst);

  Ast();

  void Display(AstNodePtr aNode, int indent) const;

  void PrintQuery(AstNodePtr aNode);

  void SetRoot(AstNodePtr aNode);

  void InsertLeft(AstNodePtr aNode, TokenPtr aToken);

  void InsertRight(AstNodePtr aNode, TokenPtr aToken);

  AstNodePtr GetRoot() const { return mRoot; };

  static AstNodePtr GetNewNode(TokenPtr aTokenPtr) { return make_shared<AstNode>(aTokenPtr); }

  ~Ast();

private:
  AstNodePtr mRoot;
};
