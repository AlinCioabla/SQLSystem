#pragma once
#include "IState.h"
class Undefined : public IState
{
public:
  Undefined();
  IState * HandleToken(TokenPtr &   aCurrentToken,
                       TokenPtr &   prevToken,
                       AstNodePtr & aCurrentInstructionNode,
                       Ast &        aAst) override;
  virtual ~Undefined();
};
