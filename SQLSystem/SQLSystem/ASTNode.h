#pragma once
#include "stdafx.h"
#include "IToken.h"

class AstNode;
typedef shared_ptr<AstNode> AstNodePtr;

class AstNode
{
public:
  AstNode(TokenPtr aToken)
    : mToken(aToken)
  {
    mLeft  = nullptr;
    mRight = nullptr;
  };
  AstNode()
    : mToken(nullptr)
    , mLeft(nullptr)
    , mRight(nullptr)
  {
  }
  AstNode(const AstNode & aAstNode);

  AstNodePtr GetLeft() const { return mLeft; };

  AstNodePtr GetRight() const { return mRight; };

  TokenPtr GetToken() const { return mToken; };

  void SetToken(TokenPtr aToken);

  void SetLeft(AstNodePtr aLeft);

  void SetRight(AstNodePtr aRight);

  ~AstNode();

private:
  TokenPtr   mToken;
  AstNodePtr mLeft;
  AstNodePtr mRight;
};
