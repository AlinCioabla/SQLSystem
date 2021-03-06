#include "stdafx.h"
#include "Distinct.h"
#include "From.h"
#include "Invalid.h"

Distinct::Distinct() = default;

unique_ptr<IState> Distinct::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "column"s);
      return nullptr;
    }

    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, "column"s);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "," && aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "comma"s);
    return nullptr;
  }

  else

    if (aCurrentToken->GetWord() == "DISTINCT" && aPrevToken->GetWord() == "SELECT")
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, "distinct");
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return nullptr;
  }

  else

    if (aCurrentToken->GetWord() == "FROM" && aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, "from"s);
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return make_unique<From>();
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Distinct::GetStateName() const
{
  return StateType::DISTINCT;
}

Distinct::~Distinct() = default;
