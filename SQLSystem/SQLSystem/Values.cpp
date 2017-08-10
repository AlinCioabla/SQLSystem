#include "stdafx.h"
#include "Values.h"

Values::Values()
{
}

IState * Values::HandleToken(TokenPtr &   aCurrentToken,
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

  return new Invalid();
}

State Values::GetStateName() const
{
  return State::VALUES;
}

Values::~Values()
{
}
