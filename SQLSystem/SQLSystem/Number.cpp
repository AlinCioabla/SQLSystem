#include "stdafx.h"
#include "Number.h"
string Number::GetWord() const
{
  return mWord;
}

TokenType Number::GetType() const
{
  return TokenType::NumberType;
}

Position Number::GetPosition() const
{
  return mPosition;
}

Number::~Number() = default;
