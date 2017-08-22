#include "stdafx.h"
#include "Helpers.h"
// string operators[]{ "+", "-", "*", "/", ":", "=", "^", "%","<", ">" };
// string punctuations[]{ ".", ",", "?", "&", "!", ";", ":", "_", "(" ")" };

bool IsAlphanumeric(const char & aChar)
{
  return ((aChar >= 'A' && aChar <= 'z') || IsDigit(aChar));
}

bool IsDigit(const char & aChar)
{
  static const string digits{ "1234567890" };
  return aChar >= '0' && aChar <= '9';
}

bool IsOperator(const char & aChar)
{
  static const string operators{ "%+-*/:=^<>" };
  return (operators.find(aChar) != string::npos);
}

bool IsPunctuation(const char & aChar)
{
  static const string punctuations{ ".,?&!;_();'" };
  return (punctuations.find(aChar) != string::npos);
}

bool IsWhitespace(const char & aChar)
{
  static const string whitespaces{ "\n " };
  return (whitespaces.find(aChar) != string::npos);
}

bool IsNumber(const string & aString)
{
  for (auto it : aString)
  {
    if (!(IsDigit(it)))
    {
      return false;
    }
  }
  return true;
}
bool IsKeyword(const string & aString)
{
  static const string keywords[]{ "DISTINCT", "SELECT", "DELETE", "UPDATE", "INSERT",
                                  "INTO",     "VALUES", "FROM",   "WHERE" };

  for (const auto & it : keywords)
  {
    if (it == aString)
    {
      return true;
    }
  }
  return false;
}

bool IsTextualOperator(const string & aString)
{
  static const string textualOperators[]{ "AND", "OR", "LIKE", "NOTLIKE" };
  for (const auto & it : textualOperators)
  {
    if (it == aString)
    {
      return true;
    }
  }
  return false;
}

TokenPtr GetNwToken(ITokensTraversal & aLexer)
{
  TokenPtr currentToken = aLexer.GetNextToken();
  while (currentToken != nullptr && currentToken->GetType() == WhiteSpaceType)
  {
    currentToken = aLexer.GetNextToken();
  }
  return move(currentToken);
}

int MatchStrings(const string & aParent, const string & aChild)
{
  int i = 0;
  while (i != aParent.size() - 1 && i != aChild.size() - 1)
  {
    if (aParent[i] != aChild[i])
    {
      return i;
    }
    i++;
  }
  return -1;
}

bool IsValidChar(const char & aChar)
{
  return (IsAlphanumeric(aChar) || IsWhitespace(aChar) || IsOperator(aChar) ||
          IsPunctuation(aChar));
}

void FormatQuery(string & aString)
{
  replace(aString.begin(), aString.end(), '\n', ' ');
  replace(aString.begin(), aString.end(), ';', ' ');

  // delete whitespace duplicates
  auto newEnd = unique(aString.begin(), aString.end(), BothAreSpaces);
  aString.erase(newEnd, aString.end());

  // delete whitespaces from beginning and from the end
  if (IsWhitespace(*aString.begin()))
  {
    aString.erase(aString.begin());
  }

  if (IsWhitespace(*(aString.end() - 1)))
  {
    aString.erase(aString.end() - 1);
  }

  // delete whitespaces next to punctuation and operators
  for (auto it = aString.begin() + 1; it != aString.end() - 2;)
  {
    if (IsWhitespace(*it) && (IsPunctuation(*(it + 1)) || IsOperator(*(it + 1)) ||
                              IsPunctuation(*(it - 1)) || IsOperator(*(it - 1))))
    {
      it = aString.erase(it);
    }
    else
    {
      ++it;
    }
  }
}

bool BothAreSpaces(char aLhs, char aRhs)
{
  return (aLhs == aRhs) && (aLhs == ' ');
}

bool IsSemicolon(char & aChar)
{
  return aChar == ';';
}