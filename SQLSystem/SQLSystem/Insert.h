#pragma once
#include "IState.h"
class Insert : public IState
{
public:
  Insert();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Insert();
};