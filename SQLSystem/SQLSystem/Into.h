#pragma once
#include "IState.h"
class Into : public IState
{
public:
  Into();
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;
  virtual ~Into();
};
