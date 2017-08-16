#include "stdafx.h"
#include "Punctuation.h"
string Punctuation::GetWord() const
{
  string s_word;
  s_word += mWord;
  return s_word;
}

TokenType Punctuation::GetType() const
{
  return TokenType::PunctuationType;
}

Position Punctuation::GetPosition() const
{
  return mPosition;
}

Punctuation::~Punctuation() = default;
