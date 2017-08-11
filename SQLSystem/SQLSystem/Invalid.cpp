#include "stdafx.h"
#include "Invalid.h"

IState * Invalid::HandleToken(TokenPtr &   aCurrentToken,
                              IToken *     prevToken,
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
