#pragma once
#include "IState.h"
class From : public IState
{
  State mNextState;

public:
  From();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  bool  TestCommand() const override;
  virtual ~From();
};