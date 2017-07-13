#include "Parser.h"

bool Parser::StartParsing()
{

	return true;
}

bool Parser::isBegin(IToken * aToken)
{
	
	return (find(mBegin.begin(), mBegin.end(), aToken->GetWord()) != mBegin.end());
	
}

bool Parser::isIntermediar(IToken * aToken)
{
	return (find(mIntermediar.begin(), mIntermediar.end(), aToken->GetWord()) != mIntermediar.end());
}

bool Parser::isFinal(IToken * aToken)
{
	return (find(mFinal.begin(), mFinal.end(), aToken->GetWord()) != mFinal.end());
}

const vector<IToken*> Parser::GetKeywords() 
{
	return mKeywords;
}

Parser::~Parser()
{
}
void Parser::SetCommands()
{

	for (auto it : mKeywords)
	{
		if (isBegin(it))
		{
			mCommands.push_back(new Begin(it));
		}
		else if (isIntermediar(it))
		{
			mCommands.push_back(new Intermediar(it));
		}

		else if (isFinal(it))
		{
			mCommands.push_back(new Final(it));
		}

	}
}