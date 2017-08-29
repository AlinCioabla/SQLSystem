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
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::OR);
      return nullptr;
    }
    if (aCurrentToken->GetWord() == "AND")
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::AND);
      return nullptr;
    }
  }

  if (aCurrentToken->GetType() == OperatorType || aCurrentToken->GetWord() == "LIKE" ||
      aCurrentToken->GetWord() == "NOTLIKE")
  {
    AstNodeType  tempType;
    const string currentWord = aCurrentToken->GetWord();

    if (currentWord == "+")
    {
      tempType = AstNodeType::PLUSOP;
    }
    else if (currentWord == "-")
    {
      tempType = AstNodeType::MINUSOP;
    }
    else if (currentWord == "/")
    {
      tempType = AstNodeType::DIVISIONOP;
    }
    else if (currentWord == "*")
    {
      tempType = AstNodeType::MULTIPLICATIONOP;
    }
    else if (currentWord == "LIKE")
    {
      tempType = AstNodeType::LIKE;
    }
    else if (currentWord == "NOTLIKE")
    {
      tempType = AstNodeType::NOTLIKE;
    }
    else if (currentWord == "=")
    {
      tempType = AstNodeType::EQUALS;
    }
    else
    {
      tempType = AstNodeType::INVALID;
    }

    if (aPrevToken->GetType() == IdentifierType)
    {
      if (aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
          aCurrentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
      {
        auto temp = aCurrentInstructionNode->GetLeft()->GetRight();
        aCurrentInstructionNode->GetLeft()->SetRight(Ast::GetNewNode(aCurrentToken, tempType));
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
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::COLUMN);
      return nullptr;
    }
    if (aPrevToken->GetWord() == "AND" || aPrevToken->GetWord() == "OR")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, AstNodeType::COLUMN);
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
          Ast::GetNewNode(aCurrentToken, AstNodeType::PREDICATE));
        return nullptr;
      }

      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, AstNodeType::PREDICATE);
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
