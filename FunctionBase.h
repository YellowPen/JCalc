#pragma once

#include <vector>

#include "Expression.h"
#include "ExpressionType.h"



class Expression;
class ExpressionType;


//Any Function defining class must inherit from FunctionBase
class FunctionBase
{
protected:
	int iden;
public:
	//Evaluates the expression
	virtual ExpressionType evaluate(Expression) = 0;
	virtual ExpressionType evaluate(std::vector<ExpressionType>) = 0;
	//Returns the name of the function
	virtual int getFuncIden() = 0;
	//Returns a string containing the name of the function
	virtual std::string getFuncName() = 0;
	//Returns the number of arguments its takes
	virtual int getFuncArgNum() = 0;
	//Returns weather or not the function is variadic
	virtual bool isVariadic() = 0;
	

	virtual void setFuncIden(int idenin) = 0;

	FunctionBase(void);
	~FunctionBase(void);
};

