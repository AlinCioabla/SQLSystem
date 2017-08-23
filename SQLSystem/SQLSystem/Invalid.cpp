#include "stdafx.h"
#include "Invalid.h"

Invalid::Invalid(TokenPtr & aTokenPtr)
{
  mInvalidToken = move(aTokenPtr);
}

unique_ptr<IState> Invalid::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();

  aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, AstNodeType::INVALID);
  return nullptr;
}

StateType Invalid::GetStateName() const
{
  return StateType::INVALID;
}

Invalid::~Invalid() = default;
