#include "stdafx.h"
#include "Parser.h"
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
  mCurrentToken = GetNwToken(mLexer);

  while (mCurrentToken != nullptr /* && mCurrentState != INVALID*/)
  {
    IState * nextState =
      mCurrentState->HandleToken(mCurrentToken, mPrevToken, mCurrentInstructionNode, mAst);

    if (nextState != nullptr)
    {
      delete mCurrentState;
      mCurrentState = nextState;
    }

    mPrevToken    = mCurrentToken;
    mCurrentToken = GetNwToken(mLexer);
  }

  return false;
}
// switch (mCurrentState)
//{
// case UNDEFINED:
//
//  else
//    TransitionTo(INVALID);
//  break;
// case VALID:
//  if (currentToken != nullptr)
//    TransitionTo(INVALID);
//  break;
// case SELECT:
// case DELETE:
// case UPDATE:

//  if (currentToken->GetType() == IdentifierType)
//  {
//    if (prevToken->GetType() == KeywordType)
//    {
//      mAst.InsertLeft(currentInstructionNode, currentToken);
//    }

//    else if (prevToken->GetWord() == ",")
//    {
//      mAst.InsertRight(currentInstructionNode->GetLeft(), currentToken);
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }

//  if (currentToken->GetWord() == ",")
//  {
//    if (prevToken->GetType() == IdentifierType)
//    {
//      mAst.InsertLeft(currentInstructionNode, currentToken);
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }
//  if (currentToken->GetWord() == "*")
//  {
//    if (prevToken->GetType() == KeywordType)
//    {
//      mAst.InsertLeft(currentInstructionNode, currentToken);
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }
//  if (currentToken->GetWord() == "DISTINCT" && prevToken->GetWord() == "SELECT")
//  {
//    if (prevToken->GetType() == KeywordType)
//    {
//      mAst.InsertRight(currentInstructionNode, currentToken);
//      currentInstructionNode = currentInstructionNode->GetRight();
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }

//  if (currentToken->GetType() == KeywordType && currentToken->GetWord() == "FROM")
//  {
//    if (prevToken->GetWord() == "*" || prevToken->GetType() == IdentifierType ||
//        prevToken->GetWord() == "DELETE")
//    {
//      mAst.InsertRight(currentInstructionNode, currentToken);
//      currentInstructionNode = currentInstructionNode->GetRight();
//      TransitionTo(FROM);
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }

// case FROM:
//  if (currentToken->GetType() == IdentifierType)
//  {
//    if (prevToken->GetType() == KeywordType)
//    {
//      mAst.InsertLeft(currentInstructionNode, currentToken);
//    }
//    else if (prevToken->GetWord() == ",")
//    {
//      mAst.InsertRight(currentInstructionNode->GetLeft(), currentToken);
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }

//  if (currentToken->GetWord() == ",")
//  {
//    if (prevToken->GetType() == IdentifierType)
//    {
//      mAst.InsertLeft(currentInstructionNode, currentToken);
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }

//  //////////////////////////////////////////////////
//  if (currentToken->GetWord() == ";")
//  {
//    if (prevToken->GetType() == IdentifierType)
//    {
//      TransitionTo(VALID);
//    }
//    else
//      TransitionTo(INVALID);
//    break;
//  }

//  /////////////////////////////////////////////////
//  if (currentToken->GetType() == KeywordType && currentToken->GetWord() == "WHERE")
//  {
//    if (prevToken->GetType() == IdentifierType)
//    {
//      TransitionTo(WHERE);
//      mAst.InsertRight(currentInstructionNode, currentToken);
//      currentInstructionNode = currentInstructionNode->GetRight();
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }

// case WHERE:
//  if (currentToken->GetWord() == "AND" || currentToken->GetWord() == "OR")
//  {
//    if (prevToken->GetType() == PredicateType || IsNumber(prevToken->GetWord()))
//    {
//      mAst.InsertLeft(currentInstructionNode, currentToken);
//    }
//    else
//      TransitionTo(INVALID);
//    break;
//  }

//  if (currentToken->GetType() == OperatorType || currentToken->GetWord() == "LIKE" ||
//      currentToken->GetWord() == "NOTLIKE")
//  {
//    if (prevToken->GetType() == IdentifierType)
//    {
//      if (currentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
//          currentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
//      {
//        auto temp = currentInstructionNode->GetLeft()->GetRight();
//        currentInstructionNode->GetLeft()->SetRight(Ast::GetNewNode(currentToken));
//        currentInstructionNode->GetLeft()->GetRight()->SetLeft(temp);
//      }
//      else
//      {
//        mAst.InsertLeft(currentInstructionNode, currentToken);
//      }
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }
//    break;
//  }

//  if (currentToken->GetType() == IdentifierType)
//  {
//    if (prevToken->GetType() == KeywordType)
//    {
//      mAst.InsertLeft(currentInstructionNode, currentToken);
//    }
//    else if (prevToken->GetWord() == "AND" || prevToken->GetWord() == "OR")
//    {
//      mAst.InsertRight(currentInstructionNode->GetLeft(), currentToken);
//    }
//    else
//    {
//      TransitionTo(INVALID);
//    }

//    break;
//  }

//  if (currentToken->GetType() == PredicateType || IsNumber(currentToken->GetWord()))
//  {
//    if (prevToken->GetType() == OperatorType || prevToken->GetWord() == "LIKE" ||
//        prevToken->GetWord() == "NOTLIKE")
//    {
//      if (currentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
//          currentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
//      {
//        currentInstructionNode->GetLeft()->GetRight()->SetRight(Ast::GetNewNode(currentToken));
//      }
//      else
//      {
//        mAst.InsertRight(currentInstructionNode->GetLeft(), currentToken);
//      }
//    }
//    else
//      TransitionTo(INVALID);

//    break;
//  }

//  //////////////////////////////////////////////////
//  if (currentToken->GetWord() == ";")
//  {
//    if (prevToken->GetType() == IdentifierType || prevToken->GetType() == PredicateType)
//    {
//      TransitionTo(VALID);
//    }
//    else
//      TransitionTo(INVALID);
//    break;
//  }
//  else
//  {
//    TransitionTo(INVALID);
//    break;
//  }
///////////////////////////////////////////////////

// default:
//  break;
//}

Ast & Parser::GetAst()
{
  return mAst;
}

Parser::~Parser()
{
}
