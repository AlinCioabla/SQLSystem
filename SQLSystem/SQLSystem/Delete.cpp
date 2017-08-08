#include "stdafx.h"
#include "Delete.h"

void Delete::TransitionTo(State aState)
{
  mNextState = aState;
}

State Delete::GetState() const
{
  return State();
}

bool Delete::TestCommand() const
{
  return false;
}

Delete::Delete() = default;

Delete::~Delete() = default;
