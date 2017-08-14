#include "stdafx.h"
#include "Valid.h"
#include "Invalid.h"

Valid::Valid() = default;

IState * Valid::HandleToken(TokenPtr &   aCurrentToken,
                            IToken *     aPrevToken,
                            AstNodePtr & aCurrentInstructionNode,
                            Ast &        aAst)
{
  return new Invalid();
}

State Valid::GetStateName() const
{
  return State::VALID;
}

Valid::~Valid() = default;
