#pragma once
#include "Position.h"
class DiagnosticInfo
{
public:
  DiagnosticInfo(int aErrorCode = 0, string aWord = "", Position aPosition = Position())
    : mErrorCode(aErrorCode)
    , mWord(aWord)
    , mPosition(aPosition){};

  ~DiagnosticInfo() = default;

private:
  int      mErrorCode;
  string   mWord;
  Position mPosition;
};
