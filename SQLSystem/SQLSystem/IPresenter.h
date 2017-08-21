#pragma once
#include "DiagnosticInfo.h"

class IPresenter
{
public:
  virtual void Present(int aTestNumber, DiagnosticInfo & aDiagInfo) = 0;
  virtual ~IPresenter(){};
};
