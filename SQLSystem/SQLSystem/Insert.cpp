#include "stdafx.h"
#include "Insert.h"
#include "Into.h"
#include "Invalid.h"
#include "Valid.h"

Insert::Insert() = default;

IState * Insert::HandleToken(TokenPtr &   aCurrentToken,
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

    if (aCurrentToken->GetWord() == "*" && aPrevToken->GetType() == KeywordType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
    return nullptr;
  }

  else

    if (aPrevToken->GetWord() == "INSERT" &&
        (aPrevToken->GetType() == KeywordType && aCurrentToken->GetWord() == "INTO"))
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return new Into();
  }

  return new Invalid(aCurrentToken);
}

State Insert::GetStateName() const
{
  return State::INSERT;
}

Insert::~Insert() = default;
