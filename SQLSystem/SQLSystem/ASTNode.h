#pragma once

#include "IToken.h"

class AstNode;
using AstNodePtr = shared_ptr<AstNode>;

enum class AstNodeType
{
  SELECT = 0,
  DISTINCT,
  FROM,
  ALL,
  COLUMN,
  TABLE,
  WHERE,
  DELETE,
  INSERT,
  INTO,
  VALUES,
  VALUE,
  OR,
  AND,
  LIKE,
  NOTLIKE,
  EQUALS,
  PLUSOP,
  MINUSOP,
  DIVISIONOP,
  MULTIPLICATIONOP,
  NUMBER,
  PREDICATE,
  COMMA,
  INVALID
};

class AstNode
{
public:
  AstNode(TokenPtr aToken, AstNodeType aType)
    : mToken(move(aToken))
    , mType(aType)
  {
  }
  AstNode() {}

  // Returns the left child
  AstNodePtr & GetLeft() { return mLeft; };

  // Returns the right child
  AstNodePtr & GetRight() { return mRight; };

  AstNodeType GetType() const { return mType; }

  // Returns the token
  IToken * GetToken() const { return mToken.get(); };

  void SetToken(TokenPtr & aToken);

  void SetLeft(const AstNodePtr & aLeft);

  void SetRight(const AstNodePtr & aRight);

  ~AstNode();

private:
  TokenPtr    mToken;
  AstNodePtr  mLeft;
  AstNodePtr  mRight;
  AstNodeType mType;
};
