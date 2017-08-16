#pragma once
#include "Position.h"
class DiagnosticInfo
{
public:
  DiagnosticInfo(int aErrorCode = 0, Position aPosition = Position(), string aWord = "")
    : mErrorCode(aErrorCode)
    , mPosition(aPosition)
    , mWord(aWord)
  {
  }

  DiagnosticInfo(const DiagnosticInfo & aDiagInfo);

  int      GetErrorCode() const;
  string   GetWord() const;
  Position GetPosition() const;

  ~DiagnosticInfo() = default;

private:
  int      mErrorCode;
  Position mPosition;
  string   mWord;
};
