#include "stdafx.h"
#include "Update.h"

Update::Update()
{
}

void Update::TransitionTo(State aState)
{
  mNextState = aState;
}

State Update::GetState() const
{
  return State();
}

Update::~Update()
{
}
