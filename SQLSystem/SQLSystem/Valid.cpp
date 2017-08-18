#include "stdafx.h"
#include "Valid.h"
#include "Invalid.h"

Valid::Valid() = default;

IState * Valid::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  return new Invalid(aCurrentToken);
}

StateName Valid::GetStateName() const
{
  return StateName::VALID;
}

Valid::~Valid() = default;
