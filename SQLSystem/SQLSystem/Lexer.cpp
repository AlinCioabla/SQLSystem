#include "stdafx.h"
#include "Lexer.h"
#include "Helpers.h"

// Read the input from a given file and store it in the member string
// of the class mSqlCommand
// If the file is not valid the method returns false and exits.

Lexer::Lexer() = default;

bool Lexer::ReadFromFile(ifstream & aIn)
{
  if (!aIn)
  {
    return false;
  }
  char c;
  while (aIn.get(c))
  {
    mSqlCommand += c;
  }
  return true;
}

// Split the input string into different types
bool Lexer::Tokenize()
{
  // Temporary string
  string _temp;
  bool   foundPredicate = false;
  // Iterate through all the initial input string characters
  for (auto it : mSqlCommand)
  {
    // If we find an alphanumeric character we add it to the
    // _temp string
    if (it == '\'' && !_temp.length() && !foundPredicate)
    {
      foundPredicate = true;
      _temp += it;
    }

    else if (it == '\'' && foundPredicate)
    {
      foundPredicate = false;
      _temp += it;
      mTokens.push_back(make_unique<Predicate>(_temp));
      _temp.clear();
    }
    else if (foundPredicate)
    {
      _temp += it;
    }
    else
    {
      if (IsAlphanumeric(it))
      {
        _temp += it;
      }
      // If we find a delimiter, we store the created _temp string as
      // a keyword token, then empty it
      else
      {
        if (_temp.length())
        {
          if (IsKeyword(_temp))
          {
            mTokens.push_back(make_unique<Keyword>(_temp));
          }
          else
          {
            mTokens.push_back(make_unique<Identifier>(_temp));
          }
          _temp.clear();
        }

        // Then we create the appropiate token for the given non alphanumeric
        // character from the input

        if (IsWhitespace(it))
        {
          mTokens.push_back(make_unique<WhiteSpace>(it));
        }
        else if (IsOperator(it))
        {
          mTokens.push_back(make_unique<Operator>(it));
        }
        else if (IsPunctuation(it))
        {
          mTokens.push_back(make_unique<Punctuation>(it));
        }
        else
        {
          // If we find a character we do not recognize, the tokenizer stops
          // and returns false

          return false;
        }
      }
    }
    mIndex = mTokens.begin();
  }

  return true;
}

TokenPtr Lexer::GetNextToken()
{
  if (this->HasNext())
  {
    if (!returnedFirstToken)
    {
      returnedFirstToken = true;
    }
    else
    {
      advance(mIndex, 1);
    }
    return move(*mIndex);
  }
  {
    return nullptr;
  }
}

bool Lexer::HasNext() const
{
  return mIndex != mTokens.end() - 1;
}

void Lexer::ResetNext()
{
  mIndex = mTokens.begin();
}

Lexer::~Lexer()
{
}
