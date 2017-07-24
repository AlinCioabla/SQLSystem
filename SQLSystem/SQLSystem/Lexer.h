#pragma once
#ifndef _LEXER_
#define _LEXER_
#include "IToken.h"
#include "ITokensTraversal.h"
#include "Identifier.h"
#include "Keyword.h"
#include "Number.h"
#include "Operator.h"
#include "Predicate.h"
#include "Punctuation.h"
#include "WhiteSpace.h"

using namespace std;

class Lexer : public ITokensTraversal
{
public:
  Lexer();

  // Checks if the file can be read and sets mSqlCommand
  bool ReadFromFile(ifstream & aIn);

  // This one tokenize mSqlCommand and stores the tokens in mTokens
  bool             Tokenize();
  string           GetSqlCommand() const { return mSqlCommand; };
  vector<IToken *> mTokens;
  IToken *         GetNextToken();

  bool HasNext() const;
  ~Lexer();

private:
  string                     mSqlCommand;
  vector<IToken *>::iterator mIndex;
  bool                       returnedFirstToken = false;
};
#endif  // !_LEXER_
