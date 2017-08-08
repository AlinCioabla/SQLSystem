#pragma once
#include "IState.h"
class Valid : public IState
{
  State mNextState;

public:
  Valid();

  virtual ~Valid();
};
