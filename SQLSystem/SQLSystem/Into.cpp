#include "stdafx.h"
#include "Into.h"
#include "From.h"
#include "Invalid.h"

Into::Into()
{
}

IState * Into::HandleToken(TokenPtr &   aCurrentToken,
                           TokenPtr &   aPrevToken,
                           AstNodePtr & aCurrentInstructionNode,
                           Ast &        aAst)
{
  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (prevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }
    else if (prevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == ",")
  {
    if (prevToken->GetType() == IdentifierType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
      return nullptr;
    }
  }

  else
    //////////////////////////////////////////////////
    if (aCurrentToken->GetWord() == ";")
  {
    if (prevToken->GetType() == IdentifierType)
    {
      return new Valid();
    }
  }

  /////////////////////////////////////////////////
  else

    if (aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "WHERE")
  {
    if (prevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return new Where();
    }
  }

  return new Invalid();
}

State Into::GetStateName() const
{
  return State::INTO;
}

Into::~Into()
{
}
