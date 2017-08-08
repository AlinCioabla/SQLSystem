#pragma once
#include "IState.h"
class Distinct : public IState
{
public:
  Distinct();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  virtual ~Distinct();
};
