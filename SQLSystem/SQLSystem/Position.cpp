#include "stdafx.h"
#include "Position.h"

Position::Position(const Position & aPosition)
{
  mColumn = aPosition.GetColumn();
  mLine   = aPosition.GetLine();
}

Position & Position::operator=(const Position & aPosition)
{
  if (this != &aPosition)
  {
    mColumn = aPosition.GetColumn();
    mLine   = aPosition.GetLine();
  }

  return *this;
}

void Position::IncrementLine()
{
  mLine++;
}

void Position::IncrementColumn()
{
  mColumn++;
}