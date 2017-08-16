#include "stdafx.h"
#include "Operator.h"
string Operator::GetWord() const
{
  string s_word;
  s_word += mWord;
  return s_word;
}

TokenType Operator::GetType() const
{
  return TokenType::OperatorType;
}

Position Operator::GetPosition() const
{
  return mPosition;
}

Operator::~Operator() = default;
