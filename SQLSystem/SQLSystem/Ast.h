#pragma once
#include "AstNode.h"

class Ast
{
public:
  Ast(AstNodePtr aRoot)
    : mRoot(move(aRoot)){};
  Ast(const Ast & aAst);

  Ast();

  // Print the Abstract Syntax Tree
  void Display(AstNode * aNode, int indent) const;

  // Print the query obtained from the Ast
  void PrintQuery(AstNode * aNode);

  // Sets the root of the ast
  void SetRoot(AstNodePtr aNode);

  // Creates a node from a token and then inserts it as the left(right) child of the current node
  // (aNode)
  void InsertLeft(AstNodePtr & aNode, TokenPtr & aToken);

  void InsertRight(AstNodePtr & aNode, TokenPtr & aToken);

  AstNode * GetRoot() const { return mRoot.get(); };

  // Creates a new node
  static AstNodePtr GetNewNode(TokenPtr & aTokenPtr) { return make_shared<AstNode>(aTokenPtr); }

  ~Ast();

private:
  AstNodePtr mRoot;
};
