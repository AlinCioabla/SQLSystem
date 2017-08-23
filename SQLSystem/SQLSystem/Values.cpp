#include "stdafx.h"
#include "Values.h"
#include "From.h"
#include "Invalid.h"
#include "Valid.h"

Values::Values() = default;

unique_ptr<IState> Values::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  auto aCurrentInstructionNode = aAst.GetCurrentInstr();
  auto aPrevToken              = aAst.GetLastAddedToken(aCurrentInstructionNode);

  if (aCurrentToken->GetType() == IdentifierType)
  {
    if (aPrevToken->GetType() == KeywordType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::VALUE);
      return nullptr;
    }

    if (aPrevToken->GetWord() == ",")
    {
      aAst.InsertRight(aCurrentInstructionNode->GetLeft(), aCurrentToken, AstNodeType::VALUE);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetWord() == ",")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertLeft(aCurrentInstructionNode, aCurrentToken, AstNodeType::COMMA);
      return nullptr;
    }
  }

  else

    if (aCurrentToken->GetType() == KeywordType && aCurrentToken->GetWord() == "FROM")
  {
    if (aPrevToken->GetWord() == "*" || aPrevToken->GetType() == IdentifierType)
    {
      aAst.InsertRight(aCurrentInstructionNode, aCurrentToken, AstNodeType::FROM);
      return make_unique<From>();
    }
  }
  else if (aCurrentToken->GetWord() == ";")
  {
    if (aPrevToken->GetType() == IdentifierType)
    {
      return make_unique<Valid>();
    }
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Values::GetStateName() const
{
  return StateType::VALUES;
}

Values::~Values() = default;
