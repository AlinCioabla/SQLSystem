#pragma once
#include "stdafx.h"
#include "IToken.h"
#include "DiagnosticInfo.h"

class ITokensTraversal
{
public:
  virtual bool ReadFromFile(ifstream & aIn) = 0;

  virtual DiagnosticInfo Tokenize() = 0;

  virtual string GetSqlCommand() const = 0;

  virtual TokenPtr GetNextToken() = 0;

  virtual bool HasNext() const = 0;

  virtual void ResetNext() = 0;

  virtual ~ITokensTraversal() = default;
};
