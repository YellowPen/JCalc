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
#include "Operators.h"
#include "Functions.h"
#include "SettingsInstance.h"

using namespace std;


void toAllLowerCase(string input)
{
	boost::algorithm::to_lower(input);
}

void regFuncsOps(SystemState* sys)
{
	
	plusO add;
	minusO sub;
	mulO mul;
	divO div;
	ExponO ex;
	sqrtF sqr;
	sinF sine(sys->Settings);

	//Load internal functions
	sys->Operators->registerOp(&add);
	sys->Operators->registerOp(&sub);
	sys->Operators->registerOp(&mul);
	sys->Operators->registerOp(&div);
	sys->Operators->registerOp(&ex);
	sys->Functions->registerFunc(&sqr);
	sys->Functions->registerFunc(&sine);
}


int main()
{
	SystemState sys_state;

	FunctionList funcs;
	OperatorList ops;
	SettingsInstance settings;

	sys_state.Functions = &funcs;
	sys_state.Operators = &ops;
	sys_state.Settings = &settings;

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