#pragma once
#include "IState.h"

class From : public IState
{
public:
  From();
  unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) override;
  StateName          GetStateName() const override;
  ~From();
};
