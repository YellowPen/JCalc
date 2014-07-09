#pragma once

#include "Expression.h"
#include "ExpressionType.h"

class Expression;
class ExpressionType;

//Any Function defining class must inherit from FunctionBase
class FunctionBase
{
public:
	//Evaluates the expression
	virtual ExpressionType evaluate(Expression) = 0;
	//Returns the name of the function
	virtual int getFuncIden() = 0;
	//Returns a string containing the name of the function
	virtual std::string getFuncName() = 0;
	//Returns the number of arguments its takes
	virtual bool getFuncArgNum() = 0;


	virtual void setFuncIden(int iden) = 0;

	FunctionBase(void);
	~FunctionBase(void);
};

