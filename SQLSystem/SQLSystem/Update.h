#pragma once
#include "IState.h"
class Update : public IState
{
  StateName mNextState;

public:
  Update();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               IToken *     aPrevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  StateName        GetStateName() const override;
  virtual ~Update();
};
