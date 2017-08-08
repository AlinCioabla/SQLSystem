#pragma once
#include "IState.h"
class Where : public IState
{
  State mNextState;

public:
  Where();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  virtual ~Where();
};
