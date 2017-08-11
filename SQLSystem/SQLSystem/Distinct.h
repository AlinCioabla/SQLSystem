#pragma once
#include "IState.h"
class Distinct : public IState
{
public:
  Distinct();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     aPrevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Distinct();
};
