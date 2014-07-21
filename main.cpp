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
#include "Screen.h"

using namespace std;


void toAllLowerCase(string input)
{
	boost::algorithm::to_lower(input);
}



int main()
{
	SystemState sys_state;

	
	
	Screen screen;
	SettingsInstance settings(&screen);
	FunctionList funcs(&screen, &settings);
	OperatorList ops;

	sys_state.Functions = &funcs;
	sys_state.Operators = &ops;
	sys_state.Settings = &settings;
	sys_state.ScreenOut = &screen;

	plusO add;
	minusO sub;
	mulO mul;
	divO div;
	ExponO ex;
	sqrtF sqr;
	sinF sine;
	modeF mode;

	sys_state.Operators->registerOp(&add);
	sys_state.Operators->registerOp(&sub);
	sys_state.Operators->registerOp(&mul);
	sys_state.Operators->registerOp(&div);
	sys_state.Operators->registerOp(&ex);
	sys_state.Functions->registerFunc(&sqr);
	sys_state.Functions->registerFunc(&sine);
	sys_state.Functions->registerFunc(&mode);

	ExpressionEvaluator eval;

	
	
	while(true)
	{
		string input;
		sys_state.ScreenOut->printCurPath();
		getline(cin, input);
		toAllLowerCase(input);

		Expression inputex(input, &sys_state);
		eval.setExpression(&inputex);

		sys_state.ScreenOut->print(eval.evaluateToStr());
	}

	return 0;
}