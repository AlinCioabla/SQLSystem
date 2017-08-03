#pragma once
#include "stdafx.h"
#include "IToken.h"
#include "Lexer.h"

class LexerTester
{
public:
  LexerTester(ifstream & aIn, Lexer & aLexer)
    : mLexer(aLexer)
    , mIn(aIn)
  {
  }

  // Tests the functionality of the given Lexer
  bool TestTokens();
  ~LexerTester();

private:
  Lexer &    mLexer;
  ifstream & mIn;
};
