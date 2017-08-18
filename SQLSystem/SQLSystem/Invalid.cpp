#include "stdafx.h"
#include "Invalid.h"

Invalid::Invalid(TokenPtr & aTokenPtr)
{
  mInvalidToken = move(aTokenPtr);
}

unique_ptr<IState> Invalid::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();

  aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
  return nullptr;
}

StateName Invalid::GetStateName() const
{
  return StateName::INVALID;
}

Invalid::~Invalid() = default;
