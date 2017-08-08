#pragma once
#include "IState.h"
class From : public IState
{
public:
  From();
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               TokenPtr &   prevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) override;
  virtual ~From();
};
