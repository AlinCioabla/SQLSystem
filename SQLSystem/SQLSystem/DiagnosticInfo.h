#pragma once
#include "Position.h"
class DiagnosticInfo
{
public:
  DiagnosticInfo(int aErrorCode, string aWord, Position aPosition)
    : mErrorCode(aErrorCode)
    , mWord(aWord)
    , mPosition(aPosition){};

  ~DiagnosticInfo() = default;

private:
  int      mErrorCode;
  string   mWord;
  Position mPosition;
};
