#pragma once
#include "IState.h"
class Select : public IState
{
  State mNextState;

public:
  Select();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  bool  TestCommand() const override;
  virtual ~Select();
};
