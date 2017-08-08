#pragma once
#include "IState.h"

class Select : public IState
{
public:
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               TokenPtr &   prevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;

  virtual ~Select();
};
