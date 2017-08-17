#pragma once

#include "IToken.h"

class AstNode;
using AstNodePtr = shared_ptr<AstNode>;

class AstNode
{
public:
  AstNode(TokenPtr aToken)
    : mToken(move(aToken))
  {
  }
  AstNode() {}

  // Returns the left child
  AstNodePtr & GetLeft() { return mLeft; };

  // Returns the right child
  AstNodePtr & GetRight() { return mRight; };

  // Returns the token
  IToken * GetToken() const { return mToken.get(); };

  void SetToken(TokenPtr & aToken);

  void SetLeft(const AstNodePtr & aLeft);

  void SetRight(const AstNodePtr & aRight);

  ~AstNode();

private:
  TokenPtr   mToken;
  AstNodePtr mLeft;
  AstNodePtr mRight;
};
