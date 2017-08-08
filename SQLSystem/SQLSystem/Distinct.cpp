#include "stdafx.h"
#include "Distinct.h"

Distinct::Distinct()
{
}

void Distinct::TransitionTo(State aState)
{
  mNextState = aState;
}

State Distinct::GetState() const
{
  return State();
}

Distinct::~Distinct()
{
}
