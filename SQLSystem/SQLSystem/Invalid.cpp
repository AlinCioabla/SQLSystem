#include "stdafx.h"
#include "Invalid.h"

Invalid::Invalid(TokenPtr & aTokenPtr)
{
  mInvalidToken = move(aTokenPtr);
}

IState * Invalid::HandleToken(TokenPtr &   aCurrentToken,
                              IToken *     aPrevToken,
                              AstNodePtr & aCurrentInstructionNode,
                              Ast &        aAst)
{
  aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
  aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
  return nullptr;
}

State Invalid::GetStateName() const
{
  return State::INVALID;
}

Invalid::~Invalid() = default;
