#pragma once
//STL
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctype.h>
//Boost

//JCPU

#include "ExpressionType.h"
#include "SystemState.h"


class SystemState;
class ExpressionType;

class Expression
{

public:


	//Converts string to Expression
	Expression(std::string input, SystemState* state);

	//Takes a raw vector of ExpressionTypes and contains it in Expression
	Expression(std::vector<ExpressionType> ExpressionVecin);

	//Adds ExpressionType to Expression
	void addExType(ExpressionType newex);

	//Returns the ExpressionType at that location
	ExpressionType at(int loc);

	//Returns the Double at that location 
	//Note: If the ExpressionType has no numeric value it will return 0.0
	double doubat(int loc);

	//Returns the String at that location 
	//Note: If the ExpressionType has no string value it will return null
	std::string stringat(int loc);

	//Returns the size of the ExpressionVec
	int length();


private:
	std::vector<std::string> inputSplit(std::string);
	std::vector<ExpressionType> ExpressionVec;
};

