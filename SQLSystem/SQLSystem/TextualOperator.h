#pragma once
#include "IToken.h"

class TextualOperator : public IToken
{
public:
  TextualOperator(string & aWord, Position aPosition)
    : mWord(aWord)
    , mPosition(aPosition){};
  string    GetWord() const override;
  TokenType GetType() const override;
  Position  GetPosition() const override;
  virtual ~TextualOperator();

private:
  string   mWord;
  Position mPosition;
};
