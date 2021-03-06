#pragma once
#include "IState.h"
class Invalid : public IState
{
public:
  Invalid(TokenPtr & aTokenPtr);
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;

  StateType GetStateName() const override;
  virtual ~Invalid();

private:
  TokenPtr mInvalidToken;
};
