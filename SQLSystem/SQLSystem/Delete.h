#pragma once
#include "IState.h"
class Delete : public IState
{
public:
  Delete();
  IState *  HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName GetStateName() const override;
  virtual ~Delete();
};
