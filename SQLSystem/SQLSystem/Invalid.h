#pragma once
#include "IState.h"
class Invalid : public IState
{
public:
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;

  virtual ~Invalid();
};
