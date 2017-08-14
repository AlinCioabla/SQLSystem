#include "stdafx.h"
#include "Undefined.h"

#include "Delete.h"
#include "Insert.h"
#include "Invalid.h"
#include "Select.h"
#include "Update.h"

Undefined::Undefined() = default;

IState * Undefined::HandleToken(TokenPtr &   aCurrentToken,
                                IToken *     prevToken,
                                AstNodePtr & aCurrentInstructionNode,
                                Ast &        aAst)
{
  if (aCurrentToken->GetWord() == "SELECT")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    aCurrentInstructionNode = tempRoot;
    return new Select();
  }
  if (aCurrentToken->GetWord() == "DELETE")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    aCurrentInstructionNode = tempRoot;
    return new Delete();
  }
  else if (aCurrentToken->GetWord() == "UPDATE")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    aCurrentInstructionNode = tempRoot;
    return new Update();
  }
  else if (aCurrentToken->GetWord() == "INSERT")
  {
    auto tempRoot = Ast::GetNewNode(aCurrentToken);
    aAst.SetRoot(tempRoot);
    aCurrentInstructionNode = tempRoot;
    return new Insert();
  }

  return new Invalid();
}

State Undefined::GetStateName() const
{
  return State::UNDEFINED;
}

Undefined::~Undefined() = default;
