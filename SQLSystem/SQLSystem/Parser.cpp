#include "Parser.h"
#include "Ast.h"
#include "Helpers.h"

Parser::Parser() {}

bool Parser::Parse(ITokensTraversal *&aLexer) {
  bool predicateHasStarted = false;

  IToken *currentToken = GetNwToken(aLexer);
  if (currentToken->GetWord() == "SELECT") {
    TransitionTo(SELECT);

  } else
    TransitionTo(INVALID);
  AstNode *root = new AstNode(currentToken);
  Ast tree(root);

  IToken *prevToken = currentToken;
  currentToken = GetNwToken(aLexer);

  while (currentToken != nullptr && mCurrentState != INVALID) {

    switch (mCurrentState) {
    case VALID:
      if (currentToken != nullptr)
        TransitionTo(INVALID);
      break;
    case SELECT:
      if (currentToken->GetType() == IdentifierType) {
        if (prevToken->GetType() != KeywordType && prevToken->GetWord() != ",")
          TransitionTo(INVALID);
        else {

          root = tree.InsertNode(root, currentToken);
        }

        break;
      }

      if (currentToken->GetWord() == ",") {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else
          root = tree.InsertNode(root, currentToken);

        break;
      }

      if (currentToken->GetType() == KeywordType &&
          currentToken->GetWord() == "FROM") {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else {
          TransitionTo(FROM);
          root = tree.InsertNode(root, currentToken);
        }

        break;
      } else {
        TransitionTo(INVALID);
        break;
      }

    case FROM:
      if (currentToken->GetType() == IdentifierType) {
        if (prevToken->GetType() != KeywordType && prevToken->GetWord() != ",")
          TransitionTo(INVALID);
        else {
          root = tree.InsertNode(root, currentToken);
        }

        break;
      }

      if (currentToken->GetWord() == ",") {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        root = tree.InsertNode(root, currentToken);

        break;
      }

      //////////////////////////////////////////////////
      if (currentToken->GetWord() == ";") {
        if (prevToken->GetType() == IdentifierType) {
          TransitionTo(VALID);
        } else
          TransitionTo(INVALID);
        break;
      }

      /////////////////////////////////////////////////
      if (currentToken->GetType() == KeywordType &&
          currentToken->GetWord() == "WHERE") {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else {
          TransitionTo(WHERE);
          root = tree.InsertNode(root, currentToken);
        }

        break;
      } else {
        TransitionTo(INVALID);
        break;
      }

    case WHERE:
      if (currentToken->GetType() == IdentifierType) {
        if (prevToken->GetType() == KeywordType ||
            prevToken->GetWord() == "," ||
            (predicateHasStarted && prevToken->GetWord() == "'")) {
          root = tree.InsertNode(root, currentToken);
        } else
          TransitionTo(INVALID);

        break;
      }

      //////////////////////////////////////////////////
      if (currentToken->GetWord() == ";") {
        if (prevToken->GetType() == IdentifierType ||
            prevToken->GetWord() == "'") {
          TransitionTo(VALID);
        } else
          TransitionTo(INVALID);
        break;
      }

      /////////////////////////////////////////////////

      if (currentToken->GetWord() == ",") {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else {
          root = tree.InsertNode(root, currentToken);
        }

        break;
      }

      if (currentToken->GetType() == KeywordType) {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else if (currentToken->GetWord() == "LIKE") {
          TransitionTo(LIKE);
          root = tree.InsertNode(root, currentToken);
        }
        break;
      }

      if (currentToken->GetType() == OperatorType &&
          currentToken->GetWord() == "=") {
        if (prevToken->GetType() != IdentifierType)
          TransitionTo(INVALID);
        else {

          root = tree.InsertNode(root, currentToken);
        }
        break;
      }

      if (currentToken->GetWord() == "'") {
        if (prevToken->GetWord() == "=") {
          predicateHasStarted = true;
        } else if (currentToken->GetWord() == "'" &&
                   prevToken->GetType() == IdentifierType)
          predicateHasStarted = false;
        else
          TransitionTo(INVALID);
        break;
      }

      if (currentToken->GetType() == IdentifierType) {
        if (prevToken->GetWord() == "'" && predicateHasStarted == true) {
          root = tree.InsertNode(root, currentToken);
          predicateHasStarted = false;
        } else
          TransitionTo(INVALID);

        break;
      } else {
        TransitionTo(INVALID);
        break;
      }

    default:
      break;
    }

    prevToken = currentToken;
    currentToken = GetNwToken(aLexer);
  }
  if (mCurrentState == VALID)
    cout << "valid";
  else
    cout << "invalid";
  tree.Display(tree.GetRoot(), 4);
  cout << endl;
  // tree.PrintInorder(root);

  return false;
}

Parser::~Parser() {}

void Parser::TransitionTo(ParserState aState) { mCurrentState = aState; }
