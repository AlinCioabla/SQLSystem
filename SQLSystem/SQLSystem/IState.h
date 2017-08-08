#pragma once
#include "stdafx.h"
#include "IToken.h"
#include "Ast.h"

enum State
{
  SELECT,
  DELETE,
  DISTINCT,
  UPDATE,
  FROM,
  WHERE,
  VALID,
  INVALID
};

class IState
{
public:
  virtual IState * HandleToken(TokenPtr &   aCurrentToken,
                               TokenPtr &   prevToken,
                               AstNodePtr & aCurrentInstructionNode,
                               Ast &        aAst) = 0;

  virtual ~IState(){};
};
