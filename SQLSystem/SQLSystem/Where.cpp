#include "stdafx.h"
#include "Where.h"
#include "From.h"
#include "Helpers.h"
#include "Invalid.h"
#include "Valid.h"

Where::Where() = default;

unique_ptr<IState> Where::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aPrevToken->GetType() == PredicateType)
  {
    if (aCurrentToken->GetWord() == "OR")
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "or");
      return nullptr;
    }
    if (aCurrentToken->GetWord() == "AND")
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "and");
      return nullptr;
    }
  }

  if (aCurrentToken->GetType() == OperatorType || aCurrentToken->GetWord() == "LIKE" ||
      aCurrentToken->GetWord() == "NOTLIKE")
  {
    string       tempType;
    const string currentWord = aCurrentToken->GetWord();

    if (currentWord == "+")
    {
      tempType = "plusop";
    }
    else if (currentWord == "-")
    {
      tempType = "minusop";
    }
    else if (currentWord == "/")
    {
      tempType = "divisionop";
    }
    else if (currentWord == "*")
    {
      tempType = "multiplicationop";
    }
    else if (currentWord == "LIKE")
    {
      tempType = "like";
    }
    else if (currentWord == "NOTLIKE")
    {
      tempType = "notlike";
    }
    else if (currentWord == "=")
    {
      tempType = "equals";
    }
    else
    {
      tempType = "invalid";
    }

    if (aPrevToken->GetType() == IdentifierType)
    {
      if (aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
          aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
      {
        auto temp = aCurrentInstructionNode->GetLeft()->GetRight();
        aCurrentInstructionNode->GetLeft()->SetRight(aAst.GetNewNode(tempType, aCurrentToken));
        aCurrentInstructionNode->GetLeft()->GetRight()->SetLeft(temp);
        return nullptr;
      }

      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, tempType);
      return nullptr;
    }
  }

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "column");
      return nullptr;
    }
    if (aPrevToken->GetWord() == "AND" || aPrevToken->GetWord() == "OR")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, "column");
      return nullptr;
    }
  }

  if (aCurrentToken->GetType() == PredicateType)
  {
    if (aPrevToken->GetType() == OperatorType || aPrevToken->GetWord() == "LIKE" ||
        aPrevToken->GetWord() == "NOTLIKE")
    {
      if (aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
          aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
      {
        aCurrentInstructionNode->GetLeft()->GetRight()->SetRight(
          aAst.GetNewNode("predicate", aCurrentToken));
        return nullptr;
      }

      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, "predicate");
      return nullptr;
    }
  }
  //////////////////////////////////////////////////
  if (aCurrentToken->GetWord() == ";" &&
      (aPrevToken->GetType() == IdentifierType || aPrevToken->GetType() == PredicateType))
  {
    return make_unique<Valid>();
  }
  /////////////////////////////////////////////////

  return make_unique<Invalid>(aCurrentToken);
}

StateType Where::GetStateName() const
{
  return StateType::WHERE;
}

Where::~Where() = default;
