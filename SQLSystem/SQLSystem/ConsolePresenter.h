#pragma once
#include "IPresenter.h"
#include "DiagnosticInfo.h"
class ConsolePresenter : public IPresenter
{
public:
  ConsolePresenter() = default;
  void Present(DiagnosticInfo & aDiagInfo) const override;
  virtual ~ConsolePresenter() = default;
};
