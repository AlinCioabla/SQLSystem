#pragma once
#include "IPresenter.h"
#include "DiagnosticInfo.h"
class ConsolePresenter : public IPresenter
{
public:
  ConsolePresenter() = default;
  void Present(size_t aTestNumber, DiagnosticInfo & aDiagInfo) override;
  virtual ~ConsolePresenter() = default;
};
