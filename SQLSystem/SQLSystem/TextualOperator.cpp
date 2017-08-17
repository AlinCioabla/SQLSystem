#include "stdafx.h"
#include "TextualOperator.h"

string TextualOperator::GetWord() const
{
  return mWord;
}

TokenType TextualOperator::GetType() const
{
  return TokenType::TextualOperatorType;
}

Position TextualOperator::GetPosition() const
{
  return mPosition;
}

TextualOperator::~TextualOperator() = default;
