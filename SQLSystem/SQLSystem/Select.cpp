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

Select::~Select()
{
}
