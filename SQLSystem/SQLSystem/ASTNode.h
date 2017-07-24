#pragma once
#include "ICommand.h"
#include "stdafx.h"
class AstNode {
public:
  AstNode(IToken *aToken) : mToken(aToken){};
  AstNode *GetLeft() const { return mLeft; };
  AstNode *GetRight() const { return mRight; };
  IToken *GetToken() const { return mToken; };
  void SetToken(IToken *aToken);
  void SetLeft(AstNode *aLeft);
  void SetRight(AstNode *aRight);

  AstNode();

  ~AstNode();

private:
  IToken *mToken;
  AstNode *mLeft;
  AstNode *mRight;
};
