#pragma once
enum State
{
  SELECT,
  DELETE,
  DISTINCT,
  UPDATE,
  FOR,
  WHERE,
  VALID,
  INVALID
};

class IState
{
public:
  virtual void  TransitionTo(State aState) = 0;
  virtual State GetState() const           = 0;

  virtual ~IState(){};
};
