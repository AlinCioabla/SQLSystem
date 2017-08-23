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
  auto tempRoot = Ast::GetNewNode(aCurrentToken, );
  aAst.SetRoot(tempRoot);

  const string currentTokenWord = tempRoot->GetToken()->GetWord();

  if (currentTokenWord == "SELECT")
  {
    return make_unique<Select>();
  }
  if (currentTokenWord == "DELETE")
  {
    return make_unique<Delete>();
  }
  if (currentTokenWord == "UPDATE")
  {
    return make_unique<Update>();
  }
  else if (currentTokenWord == "INSERT")
  {
    return make_unique<Insert>();
  }

  return make_unique<Invalid>(aCurrentToken);
}

StateType Undefined::GetStateName() const
{
  return StateType::UNDEFINED;
}

Undefined::~Undefined() = default;
