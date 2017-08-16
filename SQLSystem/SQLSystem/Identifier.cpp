#include "stdafx.h"
#include "Identifier.h"
string Identifier::GetWord() const
{
  return mWord;
}

TokenType Identifier::GetType() const
{
  return TokenType::IdentifierType;
}

Position Identifier::GetPosition() const
{
  return mPosition;
}

Identifier::~Identifier() = default;
