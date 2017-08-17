#pragma once
#include "IState.h"

class From : public IState
{
public:
  From();
  IState *  HandleToken(TokenPtr &   aCurrentToken,
                        IToken *     aPrevToken,
                        AstNodePtr & aCurrentInstructionNode,
                        Ast &        aAst) override;
  StateName GetStateName() const override;
  ~From();
};
