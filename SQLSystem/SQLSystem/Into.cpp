#include "stdafx.h"
#include "Into.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"
#include "Values.h"
#include "Where.h"

Into::Into() = default;

IState * Into::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
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
    //////////////////////////////////////////////////
    if (aCurrentToken->GetWord() == ";" && aPrevToken->GetType() == IdentifierType)
  {
    return new Valid();
  }
  /////////////////////////////////////////////////
  else

    if (aCurrentToken->GetType() == KeywordType &&
        (aCurrentToken->GetWord() == "WHERE" || aCurrentToken->GetWord() == "VALUES") &&
        aPrevToken->GetType() == IdentifierType)
  {
    if (aCurrentToken->GetWord() == "WHERE")
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      // aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return new Where();
    }
    if (aCurrentToken->GetWord() == "VALUES")
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      // aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return new Values();
    }
  }

  return new Invalid(aCurrentToken);
}

StateName Into::GetStateName() const
{
  return StateName::INTO;
}

Into::~Into() = default;
