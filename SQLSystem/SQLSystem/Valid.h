#pragma once
#include "IState.h"
class Valid : public IState
{
  State mNextState;

public:
  Valid();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               TokenPtr &   prevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  virtual ~Valid();
};
