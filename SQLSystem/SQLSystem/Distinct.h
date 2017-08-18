#pragma once
#include "IState.h"
class Distinct : public IState
{
public:
  Distinct();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName          GetStateName() const override;
  virtual ~Distinct();
};
