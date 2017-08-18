#pragma once
#include "stdafx.h"
#include "IToken.h"
#include "Ast.h"

enum StateName
{
  SELECT,
  DELETE,
  DISTINCT,
  UPDATE,
  FROM,
  WHERE,
  VALID,
  INVALID,
  UNDEFINED,
  INSERT,
  INTO,
  VALUES
};

class IState
{
public:
  virtual unique_ptr<IState> HandleToken(TokenPtr & aCurrentToken, Ast & aAst) = 0;
  virtual StateName          GetStateName() const                              = 0;

  virtual ~IState(){};
};
