#include "stdafx.h"
#include "Select.h"
#include "From.h"
#include "Invalid.h"
Select::Select() = default;

unique_ptr<IState> Select::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::COLUMN);
      return nullptr;
    }

    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, AstNodeType::COLUMN);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "," && aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::COMMA);
    return nullptr;
  }

  else

    if (aCurrentToken->GetWord() == "*" && aPrevToken->GetType() == KeywordType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::ALL);
    return nullptr;
  }

  else

    if ((aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "FROM") &&
        (aPrevToken->GetWord() == "*" || aPrevToken->GetType() == IdentifierType))
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, AstNodeType::FROM);

    return make_unique<From>();
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Select::GetStateName() const
{
  return StateType::SELECT;
}

Select::~Select() = default;
