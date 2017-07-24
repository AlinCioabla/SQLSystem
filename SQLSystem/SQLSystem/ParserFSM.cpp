#include "ParserFSM.h"

ParserFSM::~ParserFSM() = default;

ParserFSM::ParserFSM() = default;

void ParserFSM::Start(vector<IToken *> &aTokens) {
  mCurrentState = UNDEFINED;
  for (auto currentToken : aTokens) {
    if (currentToken->GetWord() == " "s) {
      continue;
    }

    switch (mCurrentState) {
    case UNDEFINED:
      if (currentToken->GetWord() == "SELECT"s) {
        TransitionTo(SELECT);
        break;
      }

      else {
        TransitionTo(INVALID);
      }
      break;

    case SELECT:
      if (currentToken->GetType() == KeywordType) {
        TransitionTo(NAME);
        break;
      } else {
        TransitionTo(INVALID);
      }
      break;
    case NAME:
      if (currentToken->GetWord() == ","s) {
        TransitionTo(EXPECTKEYWORD);
        break;
      }

      else if (currentToken->GetWord() == "FROM"s) {
        TransitionTo(FROM);
        break;
      } else {
        TransitionTo(INVALID);
      }
      break;

    case EXPECTKEYWORD:
      if (currentToken->GetType() == KeywordType) {
        TransitionTo(NAME);
      } else {
        TransitionTo(INVALID);
      }
      break;

    case FROM:
      if (currentToken->GetType() == KeywordType) {
        TransitionTo(NAME);
        break;
      } else {
        TransitionTo(INVALID);
      }
      break;
    default:
      break;
    }
  }
}

// void ParserFSM::SkipSpaces()
//{
//	while (mTokens[mIndex]->GetType() == WhiteSpaceType && mIndex <
// mTokens.size())
//	{
//		mIndex++;
//	}
//}
//
// IToken* ParserFSM::GetNextToken()
//{
//	SkipSpaces();
//	if (mIndex < mTokens.size())
//		mIndex++;
//	return mTokens[mIndex];
//}
