#include "stdafx.h"
#include "Into.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"
#include "Values.h"
#include "Where.h"

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

    if (aCurrentToken->GetType() == KeywordType &&
        (aCurrentToken->GetWord() == "WHERE" || aCurrentToken->GetWord() == "VALUES"))
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
      aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
      if (aCurrentToken->GetWord() == "WHERE")
        return new Where();
      else if (aCurrentToken->GetWord() == "VALUES")
        return new Values();
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
