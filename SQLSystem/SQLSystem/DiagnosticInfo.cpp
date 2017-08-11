#include "stdafx.h"
#include "DiagnosticInfo.h"

void DiagnosticInfo::Increment(char c)
{
  if (c == '/n')
    mLine++;
  else
    mColumn++;
}
