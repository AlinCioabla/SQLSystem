#include "stdafx.h"
#include "Invalid.h"
#include "ReWriter.h"

Invalid::Invalid(TokenPtr & aTokenPtr)
{
  mInvalidToken = move(aTokenPtr);
}

unique_ptr<IState> Invalid::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  return nullptr;
}

StateType Invalid::GetStateName() const
{
  return StateType::INVALID;
}

Invalid::~Invalid() = default;
