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
<<<<<<< HEAD
	void Start(vector <IToken*> &tokens);
	StateType GetCurrentState() { return mCurrentState; }

=======
	void Start(vector<IToken*>& aTokens);
	StateType GetCurrentState() { return mCurrentState; }
>>>>>>> afbbe6b9d07ec3efffaa254529ee0fe0f3da6e47


	~ParserFSM();

private:
	StateType mCurrentState;

	
};

