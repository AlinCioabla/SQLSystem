#pragma once

#include "IState.h"

class Undefined : public IState
{
public:
  Undefined();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType          GetStateName() const override;
  virtual ~Undefined();
};
