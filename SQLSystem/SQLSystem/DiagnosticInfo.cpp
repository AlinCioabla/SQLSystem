#include "stdafx.h"
#include "DiagnosticInfo.h"

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
