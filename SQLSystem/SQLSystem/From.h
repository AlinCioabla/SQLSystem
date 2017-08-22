#pragma once
#include "IState.h"

class From : public IState
{
public:
  From();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType          GetStateName() const override;
  ~From();
};
