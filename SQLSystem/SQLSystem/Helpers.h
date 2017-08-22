#pragma once

#include "stdafx.h"
#include "IToken.h"
#include "ITokensTraversal.h"

bool IsAlphanumeric(const char & aChar);

bool IsDigit(const char & aChar);

bool IsOperator(const char & aChar);

bool IsPunctuation(const char & aChar);

bool IsWhitespace(const char & aChar);

bool IsNumber(const string & aString);

bool IsKeyword(const string & aString);

bool IsTextualOperator(const string & aString);

TokenPtr GetNwToken(ITokensTraversal & aLexer);

int MatchStrings(const string & aParent, const string & aChild);

bool IsValidChar(const char & aChar);

void FormatQuery(string & aString);

bool BothAreSpaces(char aLhs, char aRhs);

bool IsSemicolon(char & aChar);