#pragma once
#include "IState.h"
class Valid : public IState
{
public:
  Valid();
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;
  virtual ~Valid();
};
