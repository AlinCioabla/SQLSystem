#pragma once
#include "DiagnosticInfo.h"
class Presenter
{
public:
  Presenter() = default;
  void Present(DiagnosticInfo & aDiagInfo);
  ~Presenter() = default;
};
