#pragma once
#include "IPresenter.h"
#include "DiagnosticInfo.h"
class ConsolePresenter : public IPresenter
{
public:
  ConsolePresenter() = default;
  void Present(int aTestNumber, DiagnosticInfo & aDiagInfo) override;
  virtual ~ConsolePresenter() = default;
};
