#include "stdafx.h"
#include "Where.h"
#include "From.h"
#include "Helpers.h"
#include "Invalid.h"
#include "Valid.h"

Where::Where() = default;

IState * Where::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if ((aCurrentToken->GetWord() == "AND" || aCurrentToken->GetWord() == "OR") &&
      (aPrevToken->GetType() == PredicateType || IsNumber(aPrevToken->GetWord())))
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
    return nullptr;
  }

  if (aCurrentToken->GetType() == OperatorType || aCurrentToken->GetWord() == "LIKE" ||
      aCurrentToken->GetWord() == "NOTLIKE")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      if (aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
          aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
      {
        auto temp = aCurrentInstructionNode->GetLeft()->GetRight();
        aCurrentInstructionNode->GetLeft()->SetRight(Ast::GetNewNode(aCurrentToken));
        aCurrentInstructionNode->GetLeft()->GetRight()->SetLeft(temp);
        return nullptr;
      }

      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }
  }

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }
    if (aPrevToken->GetWord() == "AND" || aPrevToken->GetWord() == "OR")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken);
      return nullptr;
    }
  }

  if (aCurrentToken->GetType() == PredicateType || IsNumber(aCurrentToken->GetWord()))
  {
    if (aPrevToken->GetType() == OperatorType || aPrevToken->GetWord() == "LIKE" ||
        aPrevToken->GetWord() == "NOTLIKE")
    {
      if (aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
          aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
      {
        aCurrentInstructionNode->GetLeft()->GetRight()->SetRight(Ast::GetNewNode(aCurrentToken));
        return nullptr;
      }

      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken);
      return nullptr;
    }
  }
  //////////////////////////////////////////////////
  if (aCurrentToken->GetWord() == ";" &&
      (aPrevToken->GetType() == IdentifierType || aPrevToken->GetType() == PredicateType))
  {
    return new Valid();
  }
  /////////////////////////////////////////////////

  return new Invalid(aCurrentToken);
}

StateName Where::GetStateName() const
{
  return StateName::WHERE;
}

Where::~Where() = default;
