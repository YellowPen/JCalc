#pragma once

#include "Expression.h"
#include "ExpressionType.h"

class Expression;
class ExpressionType;

class OperatorBase
{

protected:
	int iden;
public:

	virtual ExpressionType evaluate(Expression) = 0;
	virtual ExpressionType evaluate(ExpressionType, ExpressionType) = 0;
	virtual int getOpIden() = 0;
	virtual int getOpPres() = 0;
	virtual std::string getOpName() = 0;
	virtual bool isLeftAssociative() = 0;

	virtual void setOpIden(int iden) = 0;

	OperatorBase(void);
	~OperatorBase(void);
};

