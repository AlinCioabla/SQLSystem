#include "stdafx.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"
#include "Where.h"
From::From() = default;

unique_ptr<IState> From::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "table"s);
      return nullptr;
    }
    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, "table"s);
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
    //////////////////////////////////////////////////
    if (aCurrentToken->GetWord() == ";" && aPrevToken->GetType() == IdentifierType)
  {
    return make_unique<Valid>();
  }
  /////////////////////////////////////////////////
  else

    if (aCurrentToken->GetWord() == "WHERE" && aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, "where"s);
    return make_unique<Where>();
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType From::GetStateName() const
{
  return StateType::FROM;
}

From::~From() = default;
