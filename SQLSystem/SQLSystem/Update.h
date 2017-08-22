#pragma once
#include "IState.h"
class Update : public IState
{
  StateType mNextState;

public:
  Update();
  virtual unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType                  GetStateName() const override;
  virtual ~Update();
};
