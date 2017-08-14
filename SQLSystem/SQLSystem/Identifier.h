#pragma once
#include "IToken.h"
class Identifier : public IToken
{
public:
  Identifier(string & aWord, Position aPosition)
    : mWord(aWord)
    , mPosition(aPosition){};
  string    GetWord() const override;
  TokenType GetType() const override;
  virtual ~Identifier();

private:
  string   mWord;
  Position mPosition;
};
