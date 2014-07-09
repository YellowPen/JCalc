#pragma once

#include <vector>

#include "FunctionList.h"
#include "OperatorList.h"

class FunctionList;
class OperatorList;


//Container storing pointers to all of systems Functions and Opperators
class SystemState
{
public:
	FunctionList* Functions;
	OperatorList* Operators;

	SystemState(void)
	{
	}
	~SystemState(void)
	{
	}

};

