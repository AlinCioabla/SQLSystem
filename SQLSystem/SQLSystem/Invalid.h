#pragma once
#include "IState.h"
class Invalid : public IState
{
public:
  Invalid(TokenPtr & aTokenPtr);
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;

private:
  TokenPtr mInvalidToken;
  virtual ~Invalid();
};
