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
	//Uses deque because popping from front is neccesary
	std::deque<int> arritystack;
	bool checkParenthesis(Expression *input);

	//This is the expression thats passed if we encounter an error
	Expression getErrorExpression();
};

