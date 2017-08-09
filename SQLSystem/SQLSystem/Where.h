#pragma once
#include "IState.h"
class Where : public IState
{
  State mNextState;

public:
  Where();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               TokenPtr &   prevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  State            GetStateName() const override;
  virtual ~Where();
};
