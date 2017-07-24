#pragma once
#include "IToken.h"

// This class is for string like :SELECT, TableName, FROM...
class Keyword : public IToken
{
public:
  Keyword(string aWord)
    : mWord(aWord)
  {
  }

  TokenType GetType() const override;
  string    GetWord() const override;
  virtual ~Keyword();

private:
  string mWord;
};
