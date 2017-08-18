#pragma once
#include "IState.h"
class Values : public IState
{
public:
  Values();
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;
  virtual ~Values();
};
