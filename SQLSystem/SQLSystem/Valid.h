#pragma once
#include "IState.h"
class Valid : public IState
{
  State mNextState;

public:
  Valid();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Valid();
};
