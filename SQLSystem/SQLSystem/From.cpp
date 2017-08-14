#include "stdafx.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"
#include "Where.h"
From::From() = default;

IState * From::HandleToken(TokenPtr &   aCurrentToken,
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
    //////////////////////////////////////////////////
    if (aCurrentToken->GetWord() == ";")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      return new Valid();
    }
  }

  /////////////////////////////////////////////////
  else

    if (aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "WHERE")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      return new Where();
    }
  }

  return new Invalid();
}

State From::GetStateName() const
{
  return State::FROM;
}

From::~From() = default;
