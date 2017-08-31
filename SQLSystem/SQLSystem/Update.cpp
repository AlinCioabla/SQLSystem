#include "stdafx.h"
#include "Update.h"
#include "From.h"
#include "Invalid.h"

Update::Update() = default;

unique_ptr<IState> Update::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "column");
      return nullptr;
    }

    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, "column");
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == ",")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "comma");
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "*")
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "all");
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "FROM")
  {
    if (aPrevToken->GetWord() == "*" || aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, "from");
      return make_unique<From>();
    }
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Update::GetStateName() const
{
  return StateType::UPDATE;
}

Update::~Update() = default;
