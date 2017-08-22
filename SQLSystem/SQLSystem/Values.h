#pragma once
#include "IState.h"
class Values : public IState
{
public:
  Values();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType          GetStateName() const override;
  virtual ~Values();
};
