#pragma once
#include "stdafx.h"
#include "Position.h"

// this is the Interface for tokens objects (Operators, Punctuation and Keywords)
// we have 3 types of operators and white spaces {SELECT, *-=+ , !?; }

enum TokenType
{
  KeywordType,
  OperatorType,
  PunctuationType,
  WhiteSpaceType,
  IdentifierType,
  NumberType,
  PredicateType
};

// This is the Interface for tokens objects (Operators, Punctuation and Keywords)
class IToken
{
public:
  // This will return the type of the token
  virtual TokenType GetType() const = 0;

  // This will return the string or character stored by each token
  virtual string GetWord() const = 0;

  virtual Position GetPosition() const = 0;

  // Destructor
  virtual ~IToken(){};
};

typedef unique_ptr<IToken> TokenPtr;