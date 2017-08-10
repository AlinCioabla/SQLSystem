#pragma once

#include "IToken.h"

class AstNode;
typedef unique_ptr<AstNode> AstNodePtr;

class AstNode
{
public:
  AstNode(TokenPtr aToken)
    : mToken(move(aToken))
  {
  }
  AstNode() {}
  AstNode(const AstNode & aAstNode);

  AstNode * GetLeft() { return mLeft.get(); };

  AstNode * GetRight() { return mRight.get(); };

  IToken * GetToken() { return mToken.get(); };

  void InsertLeft(AstNodePtr aNode);

  void InsertRight(AstNodePtr aNode);

  void SetToken(TokenPtr aToken);

  void SetLeft(AstNodePtr aLeft);

  void SetRight(AstNodePtr aRight);

  ~AstNode();

private:
  TokenPtr   mToken;
  AstNodePtr mLeft;
  AstNodePtr mRight;
};
