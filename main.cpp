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
	

	string input;
	cout<<">>";
	//getline(cin, input);
	input = "3+4";
	toAllLowerCase(input);



	SystemState sys_state;

	FunctionList funcs;
	OperatorList ops;

	sys_state.Functions = &funcs;
	sys_state.Operators = &ops;

	plusO add;
	minusO sub;
	mulO mul;
	divO div;

	sys_state.Operators->registerOp(&add);
	sys_state.Operators->registerOp(&sub);
	sys_state.Operators->registerOp(&mul);
	sys_state.Operators->registerOp(&div);

	ExpressionEvaluator eval;

	Expression inputex("3*8+9-4+564+65", &sys_state);
	eval.setExpression(&inputex);
	cout<<eval.evaluateToStr();
	getchar();
}
