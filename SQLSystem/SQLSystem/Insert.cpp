#include "stdafx.h"
#include "Insert.h"
#include "Into.h"
#include "Invalid.h"
#include "Valid.h"

Insert::Insert() = default;

unique_ptr<IState> Insert::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
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

    if (aPrevToken->GetWord() == "INSERT" && aCurrentToken->GetWord() == "INTO")
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, AstNodeType::INTO);
    return make_unique<Into>();
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Insert::GetStateName() const
{
  return StateType::INSERT;
}

Insert::~Insert() = default;
