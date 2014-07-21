#pragma once

#include <vector>

#include "FunctionList.h"
#include "OperatorList.h"
#include "SettingsInstance.h"
#include "Screen.h"


class FunctionList;
class OperatorList;
class SettingsInstance;
class Screen;

//Container storing pointers to all of systems Functions and Operators
class SystemState
{
public:
	FunctionList* Functions;
	OperatorList* Operators;
	SettingsInstance* Settings;
	Screen* ScreenOut;


	SystemState(void)
	{
	}
	~SystemState(void)
	{
	}

};

