#pragma once
#include "IState.h"

class Select : public IState
{
public:
  Select();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;

  virtual ~Select();
};
