#pragma once
#include "IState.h"
class Where : public IState
{
  StateName mNextState;

public:
  Where();
  virtual unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName                  GetStateName() const override;
  virtual ~Where();
};
