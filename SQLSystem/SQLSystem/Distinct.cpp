#include "stdafx.h"
#include "Distinct.h"
#include "From.h"
#include "Invalid.h"

Distinct::Distinct()
{
}

IState * Distinct::HandleToken(TokenPtr &   aCurrentToken,
                               TokenPtr &   aPrevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst)
{
  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
    }

    else if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken);
    }
  }

  else

    if (aCurrentToken->GetWord() == ",")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
    }
  }
  else

    if (aCurrentToken->GetWord() == "DISTINCT" && aPrevToken->GetWord() == "SELECT")
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    }
  }

  else

    if (aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "FROM")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return new From();
    }
  }

  else
    return new Invalid();
}

State Distinct::GetStateName() const
{
  return State::DISTINCT;
}

Distinct::~Distinct()
{
}
