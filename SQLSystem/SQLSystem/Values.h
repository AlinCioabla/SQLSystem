#pragma once
#include "IState.h"
class Values : public IState
{
public:
  Values();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     aPrevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Values();
};
