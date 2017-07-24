#pragma once

#include "IToken.h"
#include "ITokensTraversal.h"
#include "stdafx.h"

const bool IsAlphanumeric(const char &aChar);

const bool IsDigit(const char &aChar);

const bool IsOperator(const char &aChar);

const bool IsPunctuation(const char &aChar);

const bool IsWhitespace(const char &aChar);

const bool IsNumber(const string &aString);

const bool IsKeyword(const string &aString);

IToken *GetNwToken(ITokensTraversal *&aLexer);