#pragma once
#include "IState.h"
class Update : public IState
{
  State mNextState;

public:
  Update();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               IToken *     aPrevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  State            GetStateName() const override;
  virtual ~Update();
};
