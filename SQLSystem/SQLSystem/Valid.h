#pragma once
#include "IState.h"
class Valid : public IState
{
  State mNextState;

public:
  Valid();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  virtual ~Valid();
};
