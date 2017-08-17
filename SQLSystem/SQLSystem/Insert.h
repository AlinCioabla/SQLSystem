#pragma once
#include "IState.h"
class Insert : public IState
{
public:
  Insert();
  IState *  HandleToken(TokenPtr &   aCurrentToken,
                        IToken *     aPrevToken,
                        AstNodePtr & aCurrentInstructionNode,
                        Ast &        aAst) override;
  StateName GetStateName() const override;
  virtual ~Insert();
};
