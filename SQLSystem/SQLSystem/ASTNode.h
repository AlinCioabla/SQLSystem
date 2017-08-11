#pragma once

#include "IToken.h"

class AstNode;
typedef shared_ptr<AstNode> AstNodePtr;

class AstNode
{
public:
  AstNode(TokenPtr aToken)
    : mToken(move(aToken))
  {
  }
  AstNode() {}
  AstNode(const AstNode & aAstNode);

  AstNodePtr & GetLeft() { return mLeft; };

  AstNodePtr & GetRight() { return mRight; };

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
