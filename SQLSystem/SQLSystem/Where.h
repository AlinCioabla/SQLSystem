#pragma once
#include "IState.h"
class Where : public IState
{
  StateName mNextState;

public:
  Where();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               IToken *     aPrevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  StateName        GetStateName() const override;
  virtual ~Where();
};
