#pragma once
#include "IToken.h"
class Predicate : public IToken
{
public:
  Predicate(string & aWord, Position aPosition)
    : mWord(aWord)
    , mPosition(aPosition){};
  string    GetWord() const override;
  TokenType GetType() const override;
  Position  GetPosition() const override;
  virtual ~Predicate();

private:
  string   mWord;
  Position mPosition;
};
