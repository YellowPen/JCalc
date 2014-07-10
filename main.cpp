//STL
#include <iostream>
#include <string>
//Boost
#include "boost\algorithm\string.hpp"
//JCPU
#include "Expression.h"
#include "ExpressionEvaluator.h"
#include "OperatorBase.h"
#include "SystemState.h"
#include "testDefines.h"

using namespace std;


void toAllLowerCase(string input)
{
	boost::algorithm::to_lower(input);
}


int main()
{
	SystemState sys_state;

	FunctionList funcs;
	OperatorList ops;

	sys_state.Functions = &funcs;
	sys_state.Operators = &ops;

	plusO add;
	minusO sub;
	mulO mul;
	divO div;
	sqrtF sqart;
	variadictest vtest;

	sys_state.Operators->registerOp(&add);
	sys_state.Operators->registerOp(&sub);
	sys_state.Operators->registerOp(&mul);
	sys_state.Operators->registerOp(&div);
	sys_state.Functions->registerFunc(&sqart);
	sys_state.Functions->registerFunc(&vtest);

	ExpressionEvaluator eval;
	
	
	while(true)
	{
		string input;
		cout<<"\n >>";
		getline(cin, input);
		toAllLowerCase(input);

		Expression inputex(input, &sys_state);
		eval.setExpression(&inputex);

		cout<<eval.evaluateToStr();
	}

	return 0;
}