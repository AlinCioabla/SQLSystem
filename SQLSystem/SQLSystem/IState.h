#pragma once
enum State
{
  SELECT,
  DELETE,
  DISTINCT,
  UPDATE,
  FROM,
  WHERE,
  VALID,
  INVALID
};

class IState
{
public:
  virtual void  TransitionTo(State aState) = 0;
  virtual State GetState() const           = 0;
  virtual bool  TestCommand() const        = 0;

  virtual ~IState(){};
};
