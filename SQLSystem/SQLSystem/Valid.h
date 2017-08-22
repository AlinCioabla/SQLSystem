#pragma once
#include "IState.h"
class Valid : public IState
{
public:
  Valid();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType          GetStateName() const override;
  virtual ~Valid();
};
