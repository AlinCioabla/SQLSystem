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
  bool ReadFromFile(ifstream & aIn);

  // This one tokenize mSqlCommand and stores the tokens in mTokens
  bool Tokenize();

  string GetSqlCommand() const { return mSqlCommand; };

  TokenPtr GetNextToken() override;

  bool HasNext() const;

  void ResetNext();

  ~Lexer();

private:
  string                     mSqlCommand;
  vector<TokenPtr>::iterator mIndex;
  vector<TokenPtr>           mTokens;
  bool                       returnedFirstToken = false;
  friend class LexerTest;
};
