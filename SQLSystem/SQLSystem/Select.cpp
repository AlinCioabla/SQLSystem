#include "stdafx.h"
#include "Select.h"
#include "From.h"
#include "Invalid.h"
Select::Select() = default;

IState * Select::HandleToken(TokenPtr &   aCurrentToken,
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

    else if (aPrevToken->GetWord() == ",")
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

    if (aPrevToken->GetWord() == "SELECT" && aPrevToken->GetType() == KeywordType)
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return nullptr;
  }

  else

    if ((aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "FROM") &&
        (aPrevToken->GetWord() == "*" || aPrevToken->GetType() == IdentifierType))
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
    aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    return new From();
  }

  return new Invalid(aCurrentToken);
}

State Select::GetStateName() const
{
  return State::SELECT;
}

Select::~Select() = default;
