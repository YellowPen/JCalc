#pragma once

#include <vector>
#include <string>

#include "Expression.h"
#include "ExpressionType.h"

class ExpressionType;
class Expression;

enum ExType;


class ExpressionEvaluator
{
public:
	ExpressionEvaluator(void);
	~ExpressionEvaluator(void);

	
	void setExpression(Expression* in);
	Expression evaluateToEx();
	std::string evaluateToStr();

private:
	Expression* curExpression;
	Expression shuntingParse(Expression *in);
};

