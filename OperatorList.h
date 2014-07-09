#pragma once
#include <vector>

#include "OperatorBase.h"


class OperatorBase;


//Stores pointers to all Operators and has functions for accessing them
class OperatorList
{
public:
	//Registers a Operator in the List, returns a 
	//iden that can used to access it later
	int registerOp(OperatorBase* op);

	//Given the Operator identity returns that operator 
	//object
	OperatorBase* getOp(int iden);
	OperatorBase* getOp(std::string opName);

	//Checks if the function name is registered
	bool exists(std::string opername);


	OperatorList(void);
	~OperatorList(void);

private:
	std::vector<OperatorBase*>  Operators;
	int funcidenbuffer;
};

