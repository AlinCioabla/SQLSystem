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
      if (aCurrentToken->GetWord() == "WHERE")
      {
        aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
        aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
        return new Where();
      }
      else if (aCurrentToken->GetWord() == "VALUES")
      {
        aAst.InsertRight(aCurrentInstructionNode, aCurrentToken);
        aCurrentInstructionNode = aCurrentInstructionNode->GetRight();
        return new Values();
      }
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
