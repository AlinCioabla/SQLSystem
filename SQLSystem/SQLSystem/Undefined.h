#pragma once

#include "IState.h"

class Undefined : public IState
{
public:
  Undefined();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Undefined();
};
