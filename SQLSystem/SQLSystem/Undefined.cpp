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
    aAst.SetRoot(aAst.GetNewNode("select"s, aCurrentToken));
    return make_unique<Select>();
  }
  if (currentTokenWord == "DELETE")
  {
    auto t = aAst.GetNewNode("delete"s, aCurrentToken);
    aAst.SetRoot(t);
    return make_unique<Delete>();
  }
  if (currentTokenWord == "UPDATE")
  {
    aAst.SetRoot(aAst.GetNewNode("update"s, aCurrentToken));
    return make_unique<Update>();
  }
  if (currentTokenWord == "INSERT")
  {
    aAst.SetRoot(aAst.GetNewNode("insert"s, aCurrentToken));
    return make_unique<Insert>();
  }

  aAst.SetRoot(aAst.GetNewNode("invalid"s, aCurrentToken));

  return make_unique<Invalid>(aCurrentToken);
}

StateType Undefined::GetStateName() const
{
  return StateType::UNDEFINED;
}

Undefined::~Undefined() = default;
