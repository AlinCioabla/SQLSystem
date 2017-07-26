#include "stdafx.h"
#include "Parser.h"
#include "Ast.h"
#include "Helpers.h"
Parser::Parser()
{
}

bool Parser::Parse(ITokensTraversal *& aLexer)
{
  IToken *  currentToken = GetNwToken(aLexer);
  IToken *  prevToken    = currentToken;
  AstNode * root         = new AstNode(currentToken);
  mAst.SetRoot(root);
  AstNode * currentInstructionNode = mAst.GetRoot();

  TransitionTo(UNDEFINED);

  while (currentToken != nullptr && mCurrentState != INVALID)
  {
    switch (mCurrentState)
    {
    case UNDEFINED:
      if (currentToken->GetWord() == "SELECT")
      {
        TransitionTo(SELECT);
      }
      else if (currentToken->GetWord() == "DELETE")
      {
        TransitionTo(DELETE);
      }
      else if (currentToken->GetWord() == "UPDATE")
      {
        TransitionTo(UPDATE);
      }
      else
        TransitionTo(INVALID);
      break;
    case VALID:
      if (currentToken != nullptr)
        TransitionTo(INVALID);
      break;
    case SELECT:
    case DELETE:
    case UPDATE:
    case DISTINCT:
      if (currentToken->GetType() == IdentifierType)
      {
        if (prevToken->GetType() == KeywordType)
        {
          currentInstructionNode->SetLeft(new AstNode(currentToken));
        }

        else if (prevToken->GetWord() == ",")
        {
          currentInstructionNode->GetLeft()->SetRight(new AstNode(currentToken));
        }
        else
        {
          TransitionTo(INVALID);
        }

        break;
      }

      if (currentToken->GetWord() == ",")
      {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else
        {
          AstNode * temp = currentInstructionNode->GetLeft();
          currentInstructionNode->SetLeft(new AstNode(currentToken));
          currentInstructionNode->GetLeft()->SetLeft(temp);
        }

        break;
      }
      if (currentToken->GetWord() == "*")
      {
        if (prevToken->GetType() != IdentifierType)
        {
          AstNode * temp = currentInstructionNode->GetLeft();
          currentInstructionNode->SetLeft(new AstNode(currentToken));
          currentInstructionNode->GetLeft()->SetLeft(temp);
        }
        else
          TransitionTo(INVALID);

        break;
      }
      if (currentToken->GetWord() == "DISTINCT")
      {
        if (prevToken->GetWord() == "DELETE" || prevToken->GetWord() == "UPDATE" ||
            prevToken->GetWord() == "SELECT")
        {
          TransitionTo(DISTINCT);
          currentInstructionNode->SetRight(new AstNode(currentToken));
          currentInstructionNode = currentInstructionNode->GetRight();
        }
      }

      if (currentToken->GetType() == KeywordType && currentToken->GetWord() == "FROM")
      {
        if (prevToken->GetWord() == "DELETE" || prevToken->GetWord() == "*")
        {
          TransitionTo(FROM);
          currentInstructionNode->SetRight(new AstNode(currentToken));
          currentInstructionNode = currentInstructionNode->GetRight();
        }
        else if (prevToken->GetType() != IdentifierType && prevToken->GetWord() != "DELETE")
          TransitionTo(INVALID);
        else
        {
          TransitionTo(FROM);
          currentInstructionNode->SetRight(new AstNode(currentToken));
          currentInstructionNode = currentInstructionNode->GetRight();
        }

        break;
      }
      else
      {
        TransitionTo(INVALID);
        break;
      }

    case FROM:
      if (currentToken->GetType() == IdentifierType)
      {
        if (prevToken->GetType() == KeywordType)
        {
          currentInstructionNode->SetLeft(new AstNode(currentToken));
        }
        else if (prevToken->GetWord() == ",")
        {
          currentInstructionNode->GetLeft()->SetRight(new AstNode(currentToken));
        }
        else
        {
          TransitionTo(INVALID);
        }

        break;
      }

      if (currentToken->GetWord() == ",")
      {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else
        {
          AstNode * temp = currentInstructionNode->GetLeft();
          currentInstructionNode->SetLeft(new AstNode(currentToken));
          currentInstructionNode->GetLeft()->SetLeft(temp);
        }

        break;
      }

      //////////////////////////////////////////////////
      if (currentToken->GetWord() == ";")
      {
        if (prevToken->GetType() == IdentifierType)
        {
          TransitionTo(VALID);
        }
        else
          TransitionTo(INVALID);
        break;
      }

      /////////////////////////////////////////////////
      if (currentToken->GetType() == KeywordType && currentToken->GetWord() == "WHERE")
      {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else
        {
          TransitionTo(WHERE);
          currentInstructionNode->SetRight(new AstNode(currentToken));
          currentInstructionNode = currentInstructionNode->GetRight();
        }

        break;
      }
      else
      {
        TransitionTo(INVALID);
        break;
      }

    case WHERE:
      if (currentToken->GetWord() == "AND" || currentToken->GetWord() == "OR")
      {
        if (prevToken->GetType() == PredicateType || IsNumber(prevToken->GetWord()))
        {
          AstNode * temp = currentInstructionNode->GetLeft();
          currentInstructionNode->SetLeft(new AstNode(currentToken));
          currentInstructionNode->GetLeft()->SetLeft(temp);
        }
        else
          TransitionTo(INVALID);
        break;
      }

      if (currentToken->GetType() == OperatorType || currentToken->GetWord() == "LIKE" ||
          currentToken->GetWord() == "NOTLIKE")
      {
        if (prevToken->GetType() == IdentifierType)
        {
          if (currentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
              currentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
          {
            AstNode * temp = currentInstructionNode->GetLeft()->GetRight();
            currentInstructionNode->GetLeft()->SetRight(new AstNode(currentToken));
            currentInstructionNode->GetLeft()->GetRight()->SetLeft(temp);
          }
          else
          {
            AstNode * temp = currentInstructionNode->GetLeft();
            currentInstructionNode->SetLeft(new AstNode(currentToken));
            currentInstructionNode->GetLeft()->SetLeft(temp);
          }
        }
        else
        {
          TransitionTo(INVALID);
        }
        break;
      }

      if (currentToken->GetType() == IdentifierType)
      {
        if (prevToken->GetType() == KeywordType)
        {
          currentInstructionNode->SetLeft(new AstNode(currentToken));
        }
        else if (prevToken->GetWord() == "AND" || prevToken->GetWord() == "OR")
        {
          currentInstructionNode->GetLeft()->SetRight(new AstNode(currentToken));
        }
        else
        {
          TransitionTo(INVALID);
        }

        break;
      }

      if (currentToken->GetType() == PredicateType || IsNumber(currentToken->GetWord()))
      {
        if (prevToken->GetType() == OperatorType || prevToken->GetWord() == "LIKE" ||
            prevToken->GetWord() == "NOTLIKE")
        {
          if (currentInstructionNode->GetLeft()->GetToken()->GetWord() == "AND" ||
              currentInstructionNode->GetLeft()->GetToken()->GetWord() == "OR")
          {
            currentInstructionNode->GetLeft()->GetRight()->SetRight(new AstNode(currentToken));
          }
          else
          {
            currentInstructionNode->GetLeft()->SetRight(new AstNode(currentToken));
          }
        }
        else
          TransitionTo(INVALID);

        break;
      }

      //////////////////////////////////////////////////
      if (currentToken->GetWord() == ";")
      {
        if (prevToken->GetType() == IdentifierType || prevToken->GetType() == PredicateType)
        {
          TransitionTo(VALID);
        }
        else
          TransitionTo(INVALID);
        break;
      }
      else
      {
        TransitionTo(INVALID);
        break;
      }
    /////////////////////////////////////////////////

    default:
      break;
    }

    prevToken    = currentToken;
    currentToken = GetNwToken(aLexer);
  }

  // ast.Display(ast.GetRoot(), 20);
  // cout << endl << endl;
  // ast.PrintQuery(ast.GetRoot());

  return (mCurrentState == VALID);
}

Ast & Parser::GetAst()
{
  return mAst;
}

Parser::~Parser()
{
}

void Parser::TransitionTo(ParserState aState)
{
  mCurrentState = aState;
}
