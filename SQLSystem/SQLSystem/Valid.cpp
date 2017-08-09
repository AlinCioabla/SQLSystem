#include "stdafx.h"
#include "Valid.h"

Valid::Valid()
{
}

IState * Valid::HandleToken(TokenPtr &   aCurrentToken,
                            TokenPtr &   prevToken,
                            AstNodePtr & aCurrentInstructionNode,
                            Ast &        aAst)
{
  return nullptr;
}

State Valid::GetStateName() const
{
  return State::VALID;
}

Valid::~Valid()
{
}
