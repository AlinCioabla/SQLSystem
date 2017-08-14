#include "stdafx.h"
#include "DiagnosticInfo.h"
#include "Position.h"

void Position::IncrementLine()
{
  mLine++;
}

void Position::IncrementColumn()
{
  mColumn++;
}

DiagnosticInfo::DiagnosticInfo()
{
}

DiagnosticInfo::~DiagnosticInfo()
{
}
