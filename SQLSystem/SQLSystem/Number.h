#pragma once
#include "IToken.h"
class Number : public IToken
{
public:
  Number(string & aWord)
    : mWord(aWord){};
  string    GetWord() const override;
  TokenType GetType() const override;
  Position  GetPosition() const override;
  virtual ~Number();

private:
  string   mWord;
  Position mPosition;
};
