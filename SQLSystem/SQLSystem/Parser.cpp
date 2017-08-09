#include "stdafx.h"
#include "Parser.h"
#include "IState.h"
#include "Ast.h"
#include "Helpers.h"

Parser::Parser(ITokensTraversal & aLexer)
  : mLexer(aLexer)
{
  mCurrentState           = new Undefined();
  mCurrentToken           = nullptr;
  mPrevToken              = nullptr;
  mCurrentInstructionNode = nullptr;
}

bool Parser::Parse()
{
  // Get the first token
  mCurrentToken = GetNwToken(mLexer);

  // We traverse the token list until we run out of tokens or the syntax is invalid
  while (mCurrentToken != nullptr && mCurrentState->GetStateName() != INVALID)
  {
    // Do the actions for the current state and get the next state
    IState * nextState =
      mCurrentState->HandleToken(mCurrentToken, mPrevToken, mCurrentInstructionNode, mAst);

    // If the next state is null, the current state does not change
    if (nextState != nullptr)
    {
      delete mCurrentState;
      mCurrentState = nextState;
    }

    // Get the next token
    mPrevToken    = mCurrentToken;
    mCurrentToken = GetNwToken(mLexer);
  }

  return mCurrentState->GetStateName() == VALID;
}

Ast & Parser::GetAst()
{
  return mAst;
}

Parser::~Parser()
{
}
