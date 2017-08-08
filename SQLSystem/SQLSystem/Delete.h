#pragma once
#include "IState.h"
class Delete : public IState
{
  State mNextState;

public:
  Delete();
  void  TransitionTo(State aState) override;
  State GetState() const override;
  virtual ~Delete();
};
