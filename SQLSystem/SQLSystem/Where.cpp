#include "stdafx.h"
#include "Where.h"

Where::Where()
{
}

void Where::TransitionTo(State aState)
{
  mNextState = aState;
}

State Where::GetState() const
{
  return State();
}

Where::~Where()
{
}
