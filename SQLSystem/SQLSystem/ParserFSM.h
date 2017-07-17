#pragma once
#include "stdafx.h"
#include "IToken.h"

enum StateType
{
	SELECT,
	FROM,
	NAME,
	UNDEFINED,
	WHERE,
	AND,
	OR,
	INVALID,
	EXPECTKEYWORD,
	WHITESPACE,
	SEMICOLON
};






class ParserFSM
{
public:
	ParserFSM();
	void Start(vector<IToken*> &aTokens);
	StateType GetCurrentState() { return mCurrentState; }
	~ParserFSM();

private:
	StateType mCurrentState;
	void TransitionTo(StateType aState) { mCurrentState = aState; }

	
	
};

