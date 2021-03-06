#include "stdafx.h"
#include "Predicate.h"
string Predicate::GetWord() const
{
  return mWord;
}

TokenType Predicate::GetType() const
{
  return TokenType::PredicateType;
}

Position Predicate::GetPosition() const
{
  return mPosition;
}

Predicate::~Predicate() = default;
