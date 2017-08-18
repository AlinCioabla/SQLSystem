#pragma once
#include "IState.h"
class Distinct : public IState
{
public:
  Distinct();
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;
  virtual ~Distinct();
};
