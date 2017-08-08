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

bool From::TestCommand() const
{
  return false;
}

From::~From()
{
}
