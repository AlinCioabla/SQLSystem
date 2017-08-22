#pragma once
#include "DiagnosticInfo.h"

class IPresenter
{
public:
  virtual void Present(size_t aTestNumber, DiagnosticInfo & aDiagInfo) = 0;
  virtual ~IPresenter(){};
};
