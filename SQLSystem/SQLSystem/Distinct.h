#pragma once
#include "IState.h"
class Distinct : public IState
{
  State mNextState;

public:
  Distinct();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  virtual ~Distinct();
};
