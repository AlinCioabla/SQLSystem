#pragma once
#include "IState.h"
class Where : public IState
{
  State mNextState;

public:
  Where();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               IToken *     aPrevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  State            GetStateName() const override;
  virtual ~Where();
};
