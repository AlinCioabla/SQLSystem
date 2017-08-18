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

  // We traverse the token list until we run out of tokens or the syntax is invalid
  while (mCurrentToken != nullptr && mCurrentState->GetStateName() != INVALID)
  {
    // Create a temporary pointer before we move the ownership of the currentToken

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
    auto currentInstr = mAst.GetCurrentInstr();
    // if (currentInstr != nullptr)
    {
      auto lastToken = mAst.GetLastAddedToken(currentInstr);
      return DiagnosticInfo(204, lastToken->GetPosition(), lastToken->GetWord());
    }
    // else
    //{
    //  return DiagnosticInfo(204, mCur)
    //}
  }

  return DiagnosticInfo(0);
}

Ast & Parser::GetAst()
{
  return mAst;
}

Parser::~Parser() = default;
