#pragma once
#include "IState.h"

class Select : public IState
{
public:
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;

  virtual ~Select();
};
