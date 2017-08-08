#include "stdafx.h"
#include "Select.h"

Select::Select()
{
}

void Select::TransitionTo(State aState)
{
  mNextState = aState;
}

State Select::GetState() const
{
  return State();
}

bool Select::TestCommand() const
{
  return false;
}

Select::~Select()
{
}
