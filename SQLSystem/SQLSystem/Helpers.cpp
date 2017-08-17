#include "stdafx.h"
#include "Helpers.h"
// string operators[]{ "+", "-", "*", "/", ":", "=", "^", "%","<", ">" };
// string punctuations[]{ ".", ",", "?", "&", "!", ";", ":", "_", "(" ")" };
string keywords[]{ "DISTINCT", "SELECT", "DELETE", "UPDATE", "INSERT",
                   "INTO",     "VALUES", "FROM",   "WHERE" };
string textualOperators[]{ "LIKE", "NOTLIKE", "OR", "AND" };

string operators{ "%+-*/:=^<>" };
string punctuations{ ".,?&!;_();'" };
string whitespaces{ "\n " };
string digits{ "1234567890" };

const bool IsAlphanumeric(const char & aChar)
{
  return ((aChar >= 'A' && aChar <= 'z') || IsDigit(aChar));
}

const bool IsDigit(const char & aChar)
{
  return aChar >= '0' && aChar <= '9';
}

const bool IsOperator(const char & aChar)
{
  return (operators.find(aChar) != string::npos);
}

const bool IsPunctuation(const char & aChar)
{
  return (punctuations.find(aChar) != string::npos);
}

const bool IsWhitespace(const char & aChar)
{
  return (whitespaces.find(aChar) != string::npos);
}

const bool IsNumber(const string & aString)
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

const bool IsKeyword(const string & aString)
{
  for (const auto & it : keywords)
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