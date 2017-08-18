#include "stdafx.h"
#include "Invalid.h"

Invalid::Invalid(TokenPtr & aTokenPtr)
{
  mInvalidToken = move(aTokenPtr);
}

IState * Invalid::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
  // aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
  return nullptr;
}

StateName Invalid::GetStateName() const
{
  return StateName::INVALID;
}

Invalid::~Invalid() = default;
