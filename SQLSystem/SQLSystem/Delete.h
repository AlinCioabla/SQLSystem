#pragma once
#include "IState.h"
class Delete : public IState
{
public:
  Delete();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       IToken *     aPrevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  State    GetStateName() const override;
  virtual ~Delete();
};
