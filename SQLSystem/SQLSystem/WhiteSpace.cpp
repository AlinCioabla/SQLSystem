#include "stdafx.h"
#include "WhiteSpace.h"
TokenType WhiteSpace::GetType() const
{
  return TokenType::WhiteSpaceType;
}

string WhiteSpace::GetWord() const
{
  string s_word;
  s_word += mWord;
  return s_word;
}

WhiteSpace::~WhiteSpace() = default;
