#include "stdafx.h"
#include "Select.h"
#include "From.h"
#include "Invalid.h"
Select::Select() = default;

IState * Select::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }

    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "," && aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
    return nullptr;
  }

  else

    if (aCurrentToken->GetWord() == "*" && aPrevToken->GetType() == KeywordType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
    return nullptr;
  }

  else

    if (aPrevToken->GetWord() == "SELECT" && aPrevToken->GetType() == KeywordType)
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return nullptr;
  }

  else

    if ((aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "FROM") &&
        (aPrevToken->GetWord() == "*" || aPrevToken->GetType() == IdentifierType))
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
    // aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return new From();
  }

  return new Invalid(aCurrentToken);
}

StateName Select::GetStateName() const
{
  return StateName::SELECT;
}

Select::~Select() = default;
