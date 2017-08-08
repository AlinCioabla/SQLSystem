#include "stdafx.h"
#include "Invalid.h"

Invalid::Invalid()
{
}

IState * Invalid::HandleToken(TokenPtr &   aCurrentToken,
                              TokenPtr &   prevToken,
                              AstNodePtr & aCurrentInstructionNode,
                              Ast &        aAst)
{
  return nullptr;
}

Invalid::~Invalid()
{
}
