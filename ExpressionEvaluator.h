#pragma once

#include <vector>
#include <deque>
#include <string>
#include <algorithm>

#include "Expression.h"
#include "ExpressionType.h"
#include "Error.h"


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
	//Uses deque becasue poppingfrom front is neccesary
	std::deque<int> arritystack;
};

