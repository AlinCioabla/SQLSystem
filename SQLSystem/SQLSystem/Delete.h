#pragma once
#include "IState.h"
class Delete : public IState
{
  State mNextState;

public:
  Delete();

  virtual ~Delete();
};
