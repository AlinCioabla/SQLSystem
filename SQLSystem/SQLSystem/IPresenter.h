#pragma once
#include "DiagnosticInfo.h"
class IPresenter
{
public:
  virtual void Present(DiagnosticInfo & aDiagInfo) const = 0;
  virtual ~IPresenter(){};
};
