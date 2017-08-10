#include "stdafx.h"
#include "Undefined.h"

#include "Delete.h"
#include "Insert.h"
#include "Invalid.h"
#include "Select.h"
#include "Update.h"

Undefined::Undefined()
{
}

IState * Undefined::HandleToken(TokenPtr &   aCurrentToken,
                                TokenPtr &   prevToken,
                                AstNodePtr & aCurrentInstructionNode,
                                Ast &        aAst)
{
  if (aCurrentToken->GetWord() == "SELECT")
  {
    aAst.SetRoot(Ast::GetNewNode(aCurrentToken));
    aCurrentInstructionNode = aAst.GetRoot();
    return new Select();
  }
  else if (aCurrentToken->GetWord() == "DELETE")
  {
    aAst.SetRoot(Ast::GetNewNode(aCurrentToken));
    aCurrentInstructionNode = aAst.GetRoot();
    return new Delete();
  }
  else if (aCurrentToken->GetWord() == "UPDATE")
  {
    aAst.SetRoot(Ast::GetNewNode(aCurrentToken));
    aCurrentInstructionNode = aAst.GetRoot();
    return new Update();
  }
  else if (aCurrentToken->GetWord() == "INSERT")
  {
    aAst.SetRoot(Ast::GetNewNode(aCurrentToken));
    aCurrentInstructionNode = aAst.GetRoot();
    return new Insert();
  }

  return new Invalid();
}

State Undefined::GetStateName() const
{
  return State::UNDEFINED;
}

Undefined::~Undefined()
{
}
