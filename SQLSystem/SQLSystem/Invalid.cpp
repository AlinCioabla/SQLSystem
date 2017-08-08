#include "stdafx.h"
#include "Invalid.h"

Invalid::Invalid()
{
}

void Invalid::TransitionTo(State aState)
{
  mNextState = aState;
}

State Invalid::GetState() const
{
  return State();
}

Invalid::~Invalid()
{
}
