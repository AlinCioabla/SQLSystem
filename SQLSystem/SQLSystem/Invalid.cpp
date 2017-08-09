#include "stdafx.h"
#include "Invalid.h"

IState * Invalid::HandleToken(TokenPtr &   aCurrentToken,
                              TokenPtr &   prevToken,
                              AstNodePtr & aCurrentInstructionNode,
                              Ast &        aAst)
{
  return nullptr;
}

State Invalid::GetStateName() const
{
  return State::INVALID;
}

Invalid::~Invalid()
{
}
