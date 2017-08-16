#include "stdafx.h"
#include "Keyword.h"
TokenType Keyword::GetType() const
{
  return TokenType::KeywordType;
}

string Keyword::GetWord() const
{
  return mWord;
}

Position Keyword::GetPosition() const
{
  return mPosition;
}

Keyword::~Keyword() = default;
