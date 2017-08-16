#pragma once
#include "IState.h"
class Invalid : public IState
{
public:
  Invalid(TokenPtr & aTokenPtr);
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     aPrevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;

private:
  TokenPtr mInvalidToken;
  virtual ~Invalid();
};
