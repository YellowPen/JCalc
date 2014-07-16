#pragma once

#include <vector>

#include "FunctionList.h"
#include "OperatorList.h"
#include "SettingsInstance.h"


class FunctionList;
class OperatorList;
class SettingsInstance;

//Container storing pointers to all of systems Functions and Operators
class SystemState
{
public:
	FunctionList* Functions;
	OperatorList* Operators;
	SettingsInstance* Settings;


	SystemState(void)
	{
	}
	~SystemState(void)
	{
	}

};

