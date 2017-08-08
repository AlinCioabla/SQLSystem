#pragma once
#include "IState.h"
class Update : public IState
{
  State mNextState;

public:
  Update();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               TokenPtr &   prevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  virtual ~Update();
};
