#include "stdafx.h"
#include "Valid.h"
#include "Invalid.h"

Valid::Valid() = default;

unique_ptr<IState> Valid::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  return make_unique<Invalid>(aCurrentToken);
}

StateType Valid::GetStateName() const
{
  return StateType::VALID;
}

Valid::~Valid() = default;
