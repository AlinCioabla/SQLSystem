#pragma once
#include "IState.h"
class Delete : public IState
{
public:
  Delete();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateType          GetStateName() const override;
  virtual ~Delete();
};
