#pragma once
#include "IState.h"
class Valid : public IState
{
public:
  Valid();
  IState *  HandleToken(TokenPtr &   aCurrentToken,
                        IToken *     aPrevToken,
                        AstNodePtr & aCurrentInstructionNode,
                        Ast &        aAst) override;
  StateName GetStateName() const override;
  virtual ~Valid();
};
