#pragma once

#include "IToken.h"

class AstNode;
using AstNodePtr = shared_ptr<AstNode>;

enum class AstNodeType
{
  SELECT = 0,
  DISTINCT,
  UPDATE,
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
  AstNode(TokenPtr & aToken)
    : mToken(move(aToken))
  {
  }
  AstNode();

  // Returns the left child
  AstNodePtr & GetLeft() { return mLeft; };

  // Returns the right child
  AstNodePtr & GetRight() { return mRight; };

  // Returns the token
  IToken * GetToken() const { return mToken.get(); };

  void SetToken(TokenPtr & aToken);

  void SetLeft(const AstNodePtr & aLeft);

  void SetRight(const AstNodePtr & aRight);

  virtual void Accept(Visitor & aVisitor) = 0;

  virtual ~AstNode();

private:
  TokenPtr   mToken;
  AstNodePtr mLeft;
  AstNodePtr mRight;
};
