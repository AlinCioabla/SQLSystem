#include "stdafx.h"
#include "Valid.h"

Valid::Valid()
{
}

void Valid::TransitionTo(State aState)
{
  mNextState = aState;
}

State Valid::GetState() const
{
  return State();
}

bool Valid::TestCommand() const
{
  return false;
}

Valid::~Valid()
{
}
