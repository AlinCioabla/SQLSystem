#include "stdafx.h"
#include "Lexer.h"
#include "DiagnosticInfo.h"
#include "Helpers.h"
#include "Position.h"

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

  string _inputString((istreambuf_iterator<char>(aIn)), istreambuf_iterator<char>());
  mSqlCommand = _inputString;

  return true;
}

// Split the input string into different types
DiagnosticInfo Lexer::Tokenize()
{
  Position pos(1, 1);
  // Temporary string
  string _temp;
  bool   foundPredicate = false;
  // Iterate through all the initial input string characters
  for (const auto & it : mSqlCommand)
  {
    if (it == '\n')
    {
      pos.IncrementLine();
      pos.ResetColumn();
    }

    // If we find an alphanumeric character we add it to the
    // _temp string
    if (it == '\'' && (_temp.length() == 0u) && !foundPredicate)
    {
      foundPredicate = true;
      _temp += it;
    }

    else if (it == '\'' && foundPredicate)
    {
      foundPredicate = false;
      _temp += it;
      pos.IncrementColumn();
      mTokens.push_back(make_unique<Predicate>(_temp, pos));
      _temp.clear();
    }
    else if (foundPredicate && IsValidChar(it))
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
        if (_temp.length() != 0u)
        {
          if (IsKeyword(_temp))
          {
            mTokens.push_back(make_unique<Keyword>(_temp, pos));
            pos.IncrementColumn();
          }
          else
          {
            mTokens.push_back(make_unique<Identifier>(_temp, pos));
            pos.IncrementColumn();
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
          mTokens.push_back(make_unique<Operator>(it, pos));
          pos.IncrementColumn();
        }
        else if (IsPunctuation(it))
        {
          mTokens.push_back(make_unique<Punctuation>(it, pos));
          pos.IncrementColumn();
        }
        else
        {
          // If we find a character we do not recognize, the tokenizer stops
          // and returns an error object
          _temp += it;
          return DiagnosticInfo(123, pos, _temp);
        }
      }
    }
    mIndex = mTokens.begin();
  }

  return DiagnosticInfo(0);
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
  mTokens.clear();
}
