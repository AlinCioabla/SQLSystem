#include "stdafx.h"
#include "Helpers.h"
// string operators[]{ "+", "-", "*", "/", ":", "=", "^", "%","<", ">" };
// string punctuations[]{ ".", ",", "?", "&", "!", ";", ":", "_", "(" ")" };
string keywords[]{ "DISTINCT", "SELECT", "DELETE", "UPDATE", "INSERT",
                   "INTO",     "VALUES", "FROM",   "WHERE" };
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
