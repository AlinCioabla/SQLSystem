#pragma once
#include "DiagnosticInfo.h"

class IPresenter
{
public:
  virtual void Present(DiagnosticInfo & aDiagInfo) = 0;
  virtual ~IPresenter(){};
};
