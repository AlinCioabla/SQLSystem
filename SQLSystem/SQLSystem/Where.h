#pragma once
#include "IState.h"
class Where : public IState
{
  StateType mNextState;

public:
  Where();
  virtual unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType                  GetStateName() const override;
  virtual ~Where();
};
