#include "stdafx.h"
#include "Distinct.h"
#include "From.h"
#include "Invalid.h"

Distinct::Distinct() = default;

IState * Distinct::HandleToken(TokenPtr &   aCurrentToken,
                               IToken *     aPrevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst)
{
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

    if (aCurrentToken->GetWord() == "DISTINCT" && aPrevToken->GetWord() == "SELECT")
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return nullptr;
  }

  else

    if (aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "FROM" &&
        aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return new From();
  }

  return new Invalid(aCurrentToken);
}

State Distinct::GetStateName() const
{
  return State::DISTINCT;
}

Distinct::~Distinct() = default;
