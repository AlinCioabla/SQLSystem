#pragma once


enum FirstStateType
{	
	SELECT,
	INSERT,
	DELETE,
	UPDATE
};


class IStates
{
public:
	IStates();
	~IStates();
};

