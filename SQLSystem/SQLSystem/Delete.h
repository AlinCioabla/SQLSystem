#pragma once
#include "IState.h"
class Delete : public IState
{
  State mNextState;

public:
  Delete();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;

  virtual ~Delete();
};
