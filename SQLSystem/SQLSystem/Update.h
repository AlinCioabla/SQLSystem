#pragma once
#include "IState.h"
class Update : public IState
{
  State mNextState;

public:
  Update();

  virtual ~Update();
};
