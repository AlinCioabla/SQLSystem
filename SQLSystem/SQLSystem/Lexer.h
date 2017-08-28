#pragma once

#include "IToken.h"
#include "ITokensTraversal.h"

class DiagnosticInfo;

class Lexer : public ITokensTraversal
{
public:
  Lexer();

  // Checks if the file can be read and sets mSqlCommand
  bool ReadFromFile(ifstream & aIn) override;

  // Tokenize the input and return info
  DiagnosticInfo Tokenize() override;

  // Get the initial input
  string GetSqlCommand() const override { return mSqlCommand; };

  // Get a token then advance to the next
  TokenPtr GetNextToken() override;

  // Checks if there exists another token after the current
  bool HasNext() const override;

  // Resets the token iterator
  void ResetNext() override;

  virtual ~Lexer(){};

private:
  string                     mSqlCommand;
  vector<TokenPtr>::iterator mIndex;
  vector<TokenPtr>           mTokens;
  bool                       returnedFirstToken = false;
};
