#pragma once
#include "stdafx.h"

class ITestUnit
{
public:
  virtual void ExecuteAllTests() = 0;
  // virtual void CreateTest(string aFileName) = 0;
  virtual ~ITestUnit() = default;
};
