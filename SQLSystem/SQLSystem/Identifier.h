#pragma once
#include "IToken.h"
class Identifier : public IToken {
public:
  Identifier(string &aWord) : mWord(aWord){};
  string GetWord() const override;
  TokenType GetType() const override;
  ~Identifier();

private:
  string mWord;
};
