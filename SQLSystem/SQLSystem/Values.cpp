#include "stdafx.h"
#include "Values.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"

Values::Values() = default;

IState * Values::HandleToken(TokenPtr &   aCurrentToken,
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

    if (aCurrentToken->GetWord() == ",")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }
  }

  else

    if (aPrevToken->GetWord() == "SELECT")
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "FROM")
  {
    if (aPrevToken->GetWord() == "*" || aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return new From();
    }
  }
  else if (aCurrentToken->GetWord() == ";")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      return new Valid();
    }
  }

  return new Invalid(aCurrentToken);
}

StateName Values::GetStateName() const
{
  return StateName::VALUES;
}

Values::~Values() = default;
