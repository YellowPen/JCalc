#pragma once

#include "FunctionBase.h"
#include "OperatorBase.h"

class FunctionBase;
class OperatorBase;


enum ExType{NUMERIC, STRING, MATRIX, FUNCTION, OPERATOR, COMMA, PARANTHESISO, PARANTHESISC};


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
		Operator = nullptr;
		charv = '\0';
	}

	ExpressionType(std::string strin)
	{
		Type = STRING;
		str = strin;
		numeric = 0;
		Function = nullptr;
		Operator = nullptr;
		charv = '\0';
	}

	ExpressionType(char charin)
	{
		if(charin == '(')
		{
			Type = PARANTHESISO;
			charv = charin;
			numeric = 0;
			str = "null";
			Function = nullptr;
			Operator = nullptr;
		}

		if(charin == ')')
		{
			Type = PARANTHESISC;
			charv = charin;
			numeric = 0;
			str = "null";
			Function = nullptr;
			Operator = nullptr;
		}

		if(charin == ',')
		{
			Type = COMMA;
			charv = charin;
			numeric = 0;
			str = "null";
			Function = nullptr;
			Operator = nullptr;
		}
	}

	ExpressionType(FunctionBase *Functionin)
	{
		Type = FUNCTION;
		Function = Functionin;
		Operator = nullptr;
		str = "null";
		numeric = 0;
		charv = '\0';
	}

	ExpressionType(OperatorBase *Operatorin)
	{
		Type = OPERATOR;
		Operator = Operatorin;
		Function = nullptr;
		str = "null";
		numeric = 0;
		charv = '\0';
	}

	//Consider implementing version that rather then setting all values null
	//at construction simply reads the type when asked for the value and 
	//decides if it can convert from there.

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

	FunctionBase* getFunction()
	{
		return Function;
	}

	char getChar()
	{
		return charv;
	}

private:
	std::string str;
	double numeric;
	char charv;
	FunctionBase *Function;
	OperatorBase *Operator;
};
