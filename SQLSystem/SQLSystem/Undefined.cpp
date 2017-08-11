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
                                IToken *     prevToken,
                                AstNodePtr & aCurrentInstructionNode,
                                Ast &        aAst)
{
  auto tempRoot = Ast::GetNewNode(aCurrentToken);
  if (aCurrentToken->GetWord() == "SELECT")
  {
    aAst.SetRoot(tempRoot);
    aCurrentInstructionNode = tempRoot;
    return new Select();
  }
  else if (aCurrentToken->GetWord() == "DELETE")
  {
    aAst.SetRoot(tempRoot);
    aCurrentInstructionNode = tempRoot;
    return new Delete();
  }
  else if (aCurrentToken->GetWord() == "UPDATE")
  {
    aAst.SetRoot(tempRoot);
    aCurrentInstructionNode = tempRoot;
    return new Update();
  }
  else if (aCurrentToken->GetWord() == "INSERT")
  {
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

Undefined::~Undefined()
{
}
