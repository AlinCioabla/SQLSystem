#pragma once
#include "IState.h"

class Select : public IState
{
public:
  Select();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName          GetStateName() const override;

  virtual ~Select();
};
