#include "stdafx.h"
#include "Undefined.h"

Undefined::Undefined()
{
}

IState * Undefined::HandleToken(TokenPtr &   aCurrentToken,
                                TokenPtr &   prevToken,
                                AstNodePtr & aCurrentInstructionNode,
                                Ast &        aAst)
{
  return nullptr;
}

Undefined::~Undefined()
{
}
