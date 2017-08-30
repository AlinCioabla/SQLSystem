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
  const string currentTokenWord = aCurrentToken->GetWord();

  if (currentTokenWord == "SELECT")
  {
    aAst.SetRoot(Ast::nodeFactory.GetNode("select"s, aCurrentToken));
    return make_unique<Select>();
  }
  if (currentTokenWord == "DELETE")
  {
    aAst.SetRoot(Ast::nodeFactory.GetNode("delete"s, aCurrentToken));
    return make_unique<Delete>();
  }
  if (currentTokenWord == "UPDATE")
  {
    aAst.SetRoot(Ast::nodeFactory.GetNode("update"s, aCurrentToken));
    return make_unique<Update>();
  }
  else if (currentTokenWord == "INSERT")
  {
    aAst.SetRoot(Ast::nodeFactory.GetNode("insert"s, aCurrentToken));
    return make_unique<Insert>();
  }

  aAst.SetRoot(Ast::nodeFactory.GetNode("invalid"s, aCurrentToken));

  return make_unique<Invalid>(aCurrentToken);
}

StateType Undefined::GetStateName() const
{
  return StateType::UNDEFINED;
}

Undefined::~Undefined() = default;
