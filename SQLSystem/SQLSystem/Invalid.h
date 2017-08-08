#pragma once
#include "IState.h"
class Invalid : public IState
{
  State mNextState;

public:
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;

  virtual ~Invalid();
};
