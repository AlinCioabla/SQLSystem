#pragma once
#include "IState.h"
class Values : public IState
{
public:
  Values();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Values();
};
