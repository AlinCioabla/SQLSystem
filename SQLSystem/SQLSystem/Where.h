#pragma once
#include "IState.h"
class Where : public IState
{
  State mNextState;

public:
  Where();
  virtual ~Where();
};
