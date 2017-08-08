#include "stdafx.h"
#include "From.h"

From::From()
{
}

void From::TransitionTo(State aState)
{
  mNextState = aState;
}

State From::GetState() const
{
  return State();
}

From::~From()
{
}
