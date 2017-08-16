#include "stdafx.h"
#include "DiagnosticInfo.h"

DiagnosticInfo::DiagnosticInfo(const DiagnosticInfo & aDiagInfo)
{
  mErrorCode = aDiagInfo.GetErrorCode();
  mWord      = aDiagInfo.GetWord();
  mPosition  = aDiagInfo.GetPosition();
}

int DiagnosticInfo::GetErrorCode() const
{
  return mErrorCode;
}

string DiagnosticInfo::GetWord() const
{
  return mWord;
}

Position DiagnosticInfo::GetPosition() const
{
  return mPosition;
}
