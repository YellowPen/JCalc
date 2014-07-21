#pragma once

#include <vector>

#include "FunctionBase.h"
#include "Screen.h"
#include "SettingsInstance.h"

class Screen;
class SettingsInstance;

//Stores pointers to all Functions and has functions for accessing them
class FunctionList
{
public:

	//Registers a Function in the List, returns a 
	//iden that can used to access it later
	int registerFunc(FunctionBase* func);

	
	//Given the Function identity returns that Function
	//object
	FunctionBase* getFunc(int iden);
	FunctionBase* getFunc(std::string funcname);

	//Checks if the function name is registered
	bool exists(std::string funcname);


	FunctionList(Screen*, SettingsInstance*);
	~FunctionList(void);


private:
	std::vector<FunctionBase*> Functions;
	Screen* screen;
	SettingsInstance* setting;
	int funcidenbuffer;
};

