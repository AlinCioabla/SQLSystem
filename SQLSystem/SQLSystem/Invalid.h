#pragma once
#include "IState.h"
class Invalid : public IState
{
  State mNextState;

public:
  Invalid();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  bool  TestCommand() const override;
  virtual ~Invalid();
};
