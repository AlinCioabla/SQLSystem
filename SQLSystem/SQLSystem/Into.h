#pragma once
#include "IState.h"
class Into : public IState
{
public:
  Into();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Into();
};
