#pragma once
#include "IState.h"
class Invalid : public IState
{
  State mNextState;

public:

  IState * HandleToken(TokenPtr &   aCurrentToken,
	
 virtual ~Invalid() ;
};
