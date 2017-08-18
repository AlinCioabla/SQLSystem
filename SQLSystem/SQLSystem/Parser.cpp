#include "stdafx.h"
#include "Parser.h"
#include "IState.h"
#include "Ast.h"
#include "DiagnosticInfo.h"
#include "Helpers.h"

Parser::Parser(ITokensTraversal & aLexer)
  : mLexer(aLexer)
  , mCurrentState(make_unique<Undefined>())
{
}

DiagnosticInfo Parser::Parse()
{
  // Get the first token
  mCurrentToken = GetNwToken(mLexer);

  IToken * _tempPrevToken = nullptr;

  // We traverse the token list until we run out of tokens or the syntax is invalid
  while (mCurrentToken != nullptr && mCurrentState->GetStateName() != INVALID)
  {
    // Create a temporary pointer before we move the ownership of the currentToken
    _tempPrevToken = mCurrentToken.get();

    // Do the actions for the current state and get the next state
    auto _nextState = mCurrentState->HandleToken(mCurrentToken, mAst);

    // If the next state is null, the current state does not change
    if (_nextState != nullptr)
    {
      mCurrentState = move(_nextState);
    }

    // Get the next token
    mCurrentToken = GetNwToken(mLexer);
  }

  if (mCurrentState->GetStateName() != VALID)
  {
    if (_tempPrevToken != nullptr)
    {
      return DiagnosticInfo(204, _tempPrevToken->GetPosition(), _tempPrevToken->GetWord());
    }
  }

  return DiagnosticInfo(0);
}

Ast & Parser::GetAst()
{
  return mAst;
}

Parser::~Parser() = default;
