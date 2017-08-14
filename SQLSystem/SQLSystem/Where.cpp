#include "stdafx.h"
#include "Where.h"
#include "From.h"
#include "Helpers.h"
#include "Invalid.h"
#include "Valid.h"

Where::Where() = default;

IState * Where::HandleToken(TokenPtr &   aCurrentToken,
                            IToken *     aPrevToken,
                            AstNodePtr & aCurrentInstructionNode,
                            Ast &        aAst)
{
  if (aCurrentToken->GetWord() == "AND" || aCurrentToken->GetWord() == "OR")
  {
    if (aPrevToken->GetType() == PredicateType || IsNumber(aPrevToken->GetWord()))
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }
    {
      return new Invalid();
    }
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
    else
    {
      return new Invalid();
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
    else
    {
      return new Invalid();
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
    else
    {
      return new Invalid();
    }
  }

  //////////////////////////////////////////////////
  if (aCurrentToken->GetWord() == ";")
  {
    if (aPrevToken->GetType() == IdentifierType || aPrevToken->GetType() == PredicateType)
    {
      return new Valid();
    }
    {
      return new Invalid();
    }
  }
  return new Invalid();
}

State Where::GetStateName() const
{
  return State::WHERE;
}

Where::~Where() = default;
