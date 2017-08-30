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
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "table");
      return nullptr;
    }
    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, "table");
      return nullptr;
    }
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "table");
    return nullptr;
  }

  else

    if (aCurrentToken->GetWord() == "," && aPrevToken->GetType() == IdentifierType)
  {
    aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, "comma");
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

    if (aCurrentToken->GetWord() == "WHERE")
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, "where");
    return make_unique<Where>();
  }
  if (aCurrentToken->GetWord() == "VALUES")
  {
    aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, "values");
    return make_unique<Values>();
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Into::GetStateName() const
{
  return StateType::INTO;
}

Into::~Into() = default;
