#include "stdafx.h"
#include "Valid.h"
#include "Invalid.h"

Valid::Valid()
{
}

IState * Valid::HandleToken(TokenPtr &   aCurrentToken,
                            TokenPtr &   prevToken,
                            AstNodePtr & aCurrentInstructionNode,
                            Ast &        aAst)
{
  return new Invalid();
}

State Valid::GetStateName() const
{
  return State::VALID;
}

Valid::~Valid()
{
}
