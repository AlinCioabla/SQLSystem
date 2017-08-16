#pragma once
#include "DiagnosticInfo.h"
class Presenter
{
public:
  Presenter();
  void Present(DiagnosticInfo aDiagInfo);
  ~Presenter() = default;
};
