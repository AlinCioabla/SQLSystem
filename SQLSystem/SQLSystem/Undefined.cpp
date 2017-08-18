#include "stdafx.h"
#include "Undefined.h"

#include "Delete.h"
#include "Insert.h"
#include "Invalid.h"
#include "Select.h"
#include "Update.h"

Undefined::Undefined() = default;

unique_ptr<IState> Undefined::HandleToken(TokenPtr & aCurrentToken, Ast & aAst)
{
  if (aCurrentToken->GetWord() == "SELECT")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    return make_unique<Select>();
  }
  if (aCurrentToken->GetWord() == "DELETE")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    return make_unique<Delete>();
  }
  if (aCurrentToken->GetWord() == "UPDATE")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    return make_unique<Update>();
  }
  else if (aCurrentToken->GetWord() == "INSERT")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    return make_unique<Insert>();
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateName Undefined::GetStateName() const
{
  return StateName::UNDEFINED;
}

Undefined::~Undefined() = default;
