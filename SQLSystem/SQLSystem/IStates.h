#pragma once
#include"IToken.h"

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
	WHERE
};


class IStates
{
public:
	

	IStates();
	~IStates();
};

