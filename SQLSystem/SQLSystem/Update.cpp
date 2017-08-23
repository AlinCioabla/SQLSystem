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

    if (aCurrentToken->GetWord() == ",")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::COMMA);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "*")
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::ALL);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "FROM")
  {
    if (aPrevToken->GetWord() == "*" || aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, AstNodeType::FROM);
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
