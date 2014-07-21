#include "FunctionList.h"


int FunctionList::registerFunc(FunctionBase* func)
{
	if(func->requiresSettingsInstance() == true)
	{
		func->settings = FunctionList::setting;
	}

	if(func->requiresScreen() == true)
	{
		func->screen = FunctionList::screen;
	}

	func->setFuncIden(++funcidenbuffer);
	Functions.push_back(func);
	return Functions.back()->getFuncIden();
}

FunctionBase* FunctionList::getFunc(int iden)
{
	//Search for Function 
	for(unsigned int i = 0; i<Functions.size(); i++)
	{
		if(Functions[i]->getFuncIden() == iden)
		{
			return Functions[i];
		}
	}
	//Returns nullptr if cant be found
	return nullptr;
}

FunctionBase* FunctionList::getFunc(std::string funcname)
{
	//Search for Function 
	for(unsigned int i = 0; i<Functions.size(); i++)
	{
		if(Functions[i]->getFuncName() == funcname)
		{
			return Functions[i];
		}
	}
	//Returns nullptr if cant be found
	return nullptr;
}

bool FunctionList::exists(std::string funcname)
{
	//Search for Function 
	for(unsigned int i = 0; i<Functions.size(); i++)
	{
		if(Functions[i]->getFuncName() == funcname)
		{
			return true;
		}
	}
	//Returns false if cant be found
	return false;
}

FunctionList::FunctionList(Screen* scr, SettingsInstance* sets)
{
	FunctionList::funcidenbuffer = 0;
	screen = scr;
	setting = sets;
}


FunctionList::~FunctionList(void)
{

}
