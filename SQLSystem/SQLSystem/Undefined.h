#pragma once

#include "IState.h"

class Undefined : public IState
{
public:
  Undefined();
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;
  virtual ~Undefined();
};
