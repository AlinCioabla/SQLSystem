#pragma once
#include "IState.h"
class Into : public IState
{
public:
  Into();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName          GetStateName() const override;
  virtual ~Into();
};
