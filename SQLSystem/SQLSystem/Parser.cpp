#include "stdafx.h"
#include "Parser.h"
#include "IState.h"
#include "Ast.h"
#include "Helpers.h"

Parser::Parser(ITokensTraversal & aLexer)
  : mLexer(aLexer)
  , mCurrentState(make_unique<Undefined>())
  , mPrevToken(nullptr)
{
}

bool Parser::Parse()
{
  // Get the first token
  mCurrentToken = GetNwToken(mLexer);

  IToken * _tempPrevToken;

  // We traverse the token list until we run out of tokens or the syntax is invalid
  while (mCurrentToken != nullptr && mCurrentState->GetStateName() != INVALID)
  {
    // Create a temporary pointer before we move the ownership of the currentToken
    _tempPrevToken = mCurrentToken.get();

    // Do the actions for the current state and get the next state
    IState * _nextState =
      mCurrentState->HandleToken(mCurrentToken, mPrevToken, mCurrentInstructionNode, mAst);

    // If the next state is null, the current state does not change
    if (_nextState != nullptr)
    {
      mCurrentState.reset(_nextState);
    }

    // Get the next token
    mPrevToken    = _tempPrevToken;
    mCurrentToken = GetNwToken(mLexer);
  }

  return mCurrentState->GetStateName() == VALID;
}

Ast & Parser::GetAst()
{
  return mAst;
}

Parser::~Parser() = default;
