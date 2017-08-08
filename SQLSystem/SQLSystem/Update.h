#pragma once
#include "IState.h"
class Update : public IState
{
  State mNextState;

public:
  Update();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  virtual ~Update();
};
