#pragma once
#include "stdafx.h"
#include "IToken.h"
#include "Ast.h"
#include "Delete.h"
#include "From.h"
#include "Invalid.h"
#include "Select.h"
#include "Update.h"
#include "Valid.h"
#include "Where.h"

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
