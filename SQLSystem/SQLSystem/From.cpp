#include "stdafx.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"
#include "Where.h"
From::From()
{
}

IState * From::HandleToken(TokenPtr &   aCurrentToken,
                           TokenPtr &   prevToken,
                           AstNodePtr & aCurrentInstructionNode,
                           Ast &        aAst)
{
  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (prevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
    }
    else if (prevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken);
    }
  }

  else

    if (aCurrentToken->GetWord() == ",")
  {
    if (prevToken->GetType() == IdentifierType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken);
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
      return new Where();
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
    }
  }

  return new Invalid();
}

State From::GetStateName() const
{
  return State::FROM;
}

From::~From()
{
}
