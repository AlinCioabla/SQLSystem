#pragma once
#ifndef _SQLSYSTEM_
#define _SQLSYSTEM_

#include "stdafx.h"

class SQLSystem
{
public:
	SQLSystem();

	void Start(ifstream& in);

	~SQLSystem();
};

#endif // !_SQLSYSTEM_