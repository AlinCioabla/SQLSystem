#pragma once
#include "IState.h"

class Select : public IState
{
public:
  Select();
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;

  virtual ~Select();
};
