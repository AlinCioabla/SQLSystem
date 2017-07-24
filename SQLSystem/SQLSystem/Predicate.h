#pragma once
#include "IToken.h"
class Predicate : public IToken
{
public:
  Predicate(string & aWord)
    : mWord(aWord){};
  string    GetWord() const override;
  TokenType GetType() const override;
  virtual ~Predicate();

private:
  string mWord;
};
