#include "stdafx.h"
#include "Into.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"
#include "Values.h"
#include "Where.h"

Into::Into() = default;

unique_ptr<IState> Into::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetWord() == "INSERT")
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::TABLE);
      return nullptr;
    }
    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, AstNodeType::TABLE);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == "," && aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::COMMA);
    return nullptr;
  }

  else
    //////////////////////////////////////////////////
    if (aCurrentToken->GetWord() == ";" && aPrevToken->GetType() == IdentifierType)
  {
    return make_unique<Valid>();
  }
  /////////////////////////////////////////////////
  else

    if ((aCurrentToken->GetWord() == "WHERE" || aCurrentToken->GetWord() == "VALUES") &&
        aPrevToken->GetType() == IdentifierType)
  {
    if (aCurrentToken->GetWord() == "WHERE")
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, AstNodeType::WHERE);
      return make_unique<Where>();
    }
    if (aCurrentToken->GetWord() == "VALUES")
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, AstNodeType::VALUES);
      return make_unique<Values>();
    }
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Into::GetStateName() const
{
  return StateType::INTO;
}

Into::~Into() = default;
