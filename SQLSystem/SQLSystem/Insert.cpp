#include "stdafx.h"
#include "Insert.h"
#include "Into.h"
#include "Invalid.h"
#include "Valid.h"

Insert::Insert()
{
}

IState * Insert::HandleToken(TokenPtr &   aCurrentToken,
                             TokenPtr &   aPrevToken,
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

    else if (aPrevToken->GetWord() == ",")
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

    if (aCurrentToken->GetWord() == "*")
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }
  }

  else

    if (aPrevToken->GetWord() == "INSERT")
  {
    if (aPrevToken->GetType() == KeywordType && aCurrentToken->GetWord() == "INTO")
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return new Into();
    }
  }
  else
    return new Invalid();
}

State Insert::GetStateName() const
{
  return State::INSERT;
}

Insert::~Insert()
{
}