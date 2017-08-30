#pragma once
#include "AstNode.h"
#include "NodeFactory.h"

class Ast
{
public:
  Ast(AstNodePtr aRoot)
    : mRoot(move(aRoot)){};

  Ast();

  // Sets the root of the ast
  void SetRoot(AstNodePtr aNode);

  // Creates a node from a token and then inserts it as the left(right) child of the current node
  // (aNode)
  void InsertLeft(AstNodePtr & aNode, TokenPtr & aToken, string aNodeType);

  void InsertRight(AstNodePtr & aNode, TokenPtr & aToken, string aNodeType);

  // Returns a const pointer to the last added node's token of the given node as parameter
  IToken * GetLastAddedToken(AstNodePtr & aNode) const;

  // Returns a copy of the current instruction node
  AstNodePtr GetCurrentInstr() const;
  void       ConstructQueryFromAst(AstNode * aNode);

  AstNode * GetRoot() const { return mRoot.get(); };

  ~Ast();

  static NodeFactory nodeFactory;

private:
  AstNodePtr mRoot;
  string     mAstQuery;
};
