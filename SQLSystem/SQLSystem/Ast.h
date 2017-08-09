#pragma once
#include "AstNode.h"

class Ast
{
public:
  Ast(AstNodePtr aRoot)
    : mRoot(aRoot){};
  Ast(const Ast & aAst);

  Ast();

  // Print the Abstract Syntax Tree
  void Display(AstNodePtr aNode, int indent) const;

  // Print the query obtained from the Ast
  void PrintQuery(AstNodePtr aNode);

  // Sets the root of the ast
  void SetRoot(AstNodePtr aNode);

  // Creates a node from a token and then inserts it as the left(right) child of the current node
  // (aNode)
  void InsertLeft(AstNodePtr aNode, TokenPtr aToken);

  void InsertRight(AstNodePtr aNode, TokenPtr aToken);

  AstNodePtr GetRoot() const { return mRoot; };

  // Creates a new node
  static AstNodePtr GetNewNode(TokenPtr aTokenPtr) { return make_shared<AstNode>(aTokenPtr); }

  ~Ast();

private:
  AstNodePtr mRoot;
};
