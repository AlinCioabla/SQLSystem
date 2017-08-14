#pragma once
#include "IToken.h"

// This class is for string like :{ "+-*/=^%<>" };
class Operator : public IToken
{
public:
  Operator(char aWord, Position aPosition)
    : mWord(aWord)
    , mPosition(aPosition){};
  string    GetWord() const override;
  TokenType GetType() const override;
  virtual ~Operator();

private:
  char     mWord;
  Position mPosition;
};
