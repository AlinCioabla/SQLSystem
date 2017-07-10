#pragma once
#include "stdafx.h"
#include "IToken.h"

enum StateType
{
	ALL,
	AND,
	BETWEEN,
	CREATE_TABLE,
	DELETE,
	FROM,
	IN,
	INSERT,
	INSERT_INTO,
	LIKE,
	OR,
	ORDER_BY,
	NOT,
	STAR,
	SET,
	SELECT,
	UPDATE,
	WHERE,
	NAME
};


class ParserFSM
{
public:
	ParserFSM();

	void TransitionTo(StateType aState) { mCurrentState = aState; }
	void Start(vector <IToken*> &tokens);
	StateType GetCurrentState() { return mCurrentState; }



	~ParserFSM();

private:
	StateType mCurrentState;

	
};

