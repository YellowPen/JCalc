#pragma once

#include "FunctionBase.h"
#include "OperatorBase.h"

class FunctionBase;
class OperatorBase;


enum ExType{NUMERIC, STRING, MATRIX, FUNCTION, OPERATOR, COMMA};


class ExpressionType
{
public:
	ExType Type;

	ExpressionType(double numericin)
	{
		Type = NUMERIC;
		numeric = numericin;
		str = "null";
		Function = nullptr;
	}

	ExpressionType(std::string strin)
	{
		Type = STRING;
		str = strin;
		numeric = 0;
		Function = nullptr;
	}

	ExpressionType(FunctionBase *Functionin)
	{
		Type = FUNCTION;
		Function = Functionin;
		str = "null";
		numeric = 0;
	}

	ExpressionType(OperatorBase *Operatorin)
	{
		Type = OPERATOR;
		Operator = Operatorin;
		Function = nullptr;
		str = "null";
		numeric = 0;
	}

	double getNumeric()
	{
		return numeric;
	}

	std::string getString()
	{
		return str;
	}

	OperatorBase* getOperator()
	{
		return Operator;
	}

private:
	std::string str;
	double numeric;
	FunctionBase *Function;
	OperatorBase *Operator;
};
