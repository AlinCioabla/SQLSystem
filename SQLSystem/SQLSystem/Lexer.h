#pragma once

#include "IToken.h"
#include "ITokensTraversal.h"
#include "Identifier.h"
#include "Keyword.h"
#include "Number.h"
#include "Operator.h"
#include "Predicate.h"
#include "Punctuation.h"
#include "WhiteSpace.h"

class Lexer : public ITokensTraversal
{
public:
  Lexer();

  // Checks if the file can be read and sets mSqlCommand
  bool ReadFromFile(ifstream & aIn) override;

  // This one tokenize mSqlCommand and stores the tokens in mTokens
  bool Tokenize() override;

  // Get the initial input
  string GetSqlCommand() const override { return mSqlCommand; };

  // Get a token then advance to the next
  TokenPtr GetNextToken() override;

  // Checks if there exists another token after the current
  bool HasNext() const override;

  // Resets the token iterator
  void ResetNext() override;

  ~Lexer();

private:
  string                     mSqlCommand;
  vector<TokenPtr>::iterator mIndex;
  vector<TokenPtr>           mTokens;
  bool                       returnedFirstToken = false;
  friend class LexerTest;
};
