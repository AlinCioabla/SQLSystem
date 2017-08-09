#pragma once
#include "IState.h"
class Invalid : public IState
{
public:
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;

  virtual ~Invalid();
};
