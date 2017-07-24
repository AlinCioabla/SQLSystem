#include "Parser.h"
#include "Ast.h"
#include "Helpers.h"

Parser::Parser()
{
}

bool Parser::Parse(ITokensTraversal *& aLexer)
{
  bool predicateHasStarted = false;

  IToken * currentToken = GetNwToken(aLexer);
  if (currentToken->GetWord() == "SELECT")
  {
    TransitionTo(SELECT);
  }
  else
    TransitionTo(INVALID);

  AstNode * root                   = new AstNode(currentToken);
  AstNode * currentInstructionNode = root;
  Ast       ast(root);

  IToken * prevToken = currentToken;
  currentToken       = GetNwToken(aLexer);

  while (currentToken != nullptr && mCurrentState != INVALID)
  {
    ast.Display(ast.GetRoot(), 4);
    cout << endl << endl;

    switch (mCurrentState)
    {
    case VALID:
      if (currentToken != nullptr)
        TransitionTo(INVALID);
      break;
    case SELECT:
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

      if (currentToken->GetType() == KeywordType && currentToken->GetWord() == "FROM")
      {
        if (prevToken->GetType() != IdentifierType)
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
      if (currentToken->GetType() == IdentifierType)
      {
        if (prevToken->GetType() == KeywordType)
        {
        }
        else
          TransitionTo(INVALID);

        break;
      }

      //////////////////////////////////////////////////
      if (currentToken->GetWord() == ";")
      {
        if (prevToken->GetType() == IdentifierType || prevToken->GetWord() == "'")
        {
          TransitionTo(VALID);
        }
        else
          TransitionTo(INVALID);
        break;
      }

      /////////////////////////////////////////////////

      if (currentToken->GetType() == KeywordType)
      {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else if (currentToken->GetWord() == "LIKE")
        {
        }
        break;
      }

      if (currentToken->GetType() == OperatorType && currentToken->GetWord() == "=")
      {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else
        {
        }
        break;
      }

      if (currentToken->GetWord() == "'")
      {
        if (prevToken->GetWord() == "=")
        {
          predicateHasStarted = true;
        }
        else if (currentToken->GetWord() == "'" && prevToken->GetType() == IdentifierType)
          predicateHasStarted = false;
        else
          TransitionTo(INVALID);
        break;
      }

      if (currentToken->GetType() == IdentifierType)
      {
        if (prevToken->GetWord() == "'" && predicateHasStarted == true)
        {
          predicateHasStarted = false;
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

    default:
      break;
    }

    prevToken    = currentToken;
    currentToken = GetNwToken(aLexer);
  }
  if (mCurrentState == VALID)
    cout << "valid";
  else
    cout << "invalid";

  return false;
}

Parser::~Parser()
{
}

void Parser::TransitionTo(ParserState aState)
{
  mCurrentState = aState;
}
