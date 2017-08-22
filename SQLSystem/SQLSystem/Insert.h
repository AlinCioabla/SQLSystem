#pragma once
#include "IState.h"
class Insert : public IState
{
public:
  Insert();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType          GetStateName() const override;
  virtual ~Insert();
};
