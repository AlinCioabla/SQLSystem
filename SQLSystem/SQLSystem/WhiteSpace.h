#pragma once
#include "IToken.h"

// This class is for string like :"   ";
class WhiteSpace : public IToken
{
public:
  WhiteSpace(char aWord)
    : mWord(aWord)
  {
  }

  TokenType GetType() const override;
  string    GetWord() const override;
  Position  GetPosition() const override;
  ~WhiteSpace();

private:
  char mWord;
};
