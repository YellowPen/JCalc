#include "ExpressionEvaluator.h"


ExpressionEvaluator::ExpressionEvaluator(void)
{
}


ExpressionEvaluator::~ExpressionEvaluator(void)
{
}

void ExpressionEvaluator::setExpression(Expression* in)
{
	ExpressionEvaluator::curExpression = in;
}

//See: http://en.wikipedia.org/wiki/Shunting-yard_algorithm
Expression ExpressionEvaluator::shuntingParse(Expression *input)
{
	std::vector<ExpressionType> stack;
	std::vector<ExpressionType> outputqueue;
	std::deque<int> arrity;

	for(int i = 0; i < input->length(); i++)
	{

		//Set currentExpressionComp to the input at i
		ExpressionType currentExComponent = input->at(i);

		if(currentExComponent.Type == NUMERIC)
		{
			outputqueue.push_back(currentExComponent);
		}

		else if(currentExComponent.Type == FUNCTION)
		{
			stack.push_back(currentExComponent);
			if(currentExComponent.getFunction()->isVariadic())
			{
				arrity.push_back(1);
			}
		}

		else if(currentExComponent.Type == COMMA)
		{
			arrity.back()++;
			while(stack.back().Type != PARANTHESISO)
			{
				outputqueue.push_back(stack.back());
				stack.pop_back();

				if(stack.empty())
				{
					JcpuError("Error1: Mismatched Parenthesis?");
					break;
				}
			}
		}

		else if(currentExComponent.Type == OPERATOR)
		{
	
				while(stack.empty() == false && stack.back().Type == OPERATOR)
				{
					//Check if the current operator is left associative
					if(currentExComponent.getOperator()->isLeftAssociative())
					{
						//if current operator is greater then or equal too the operator in the back of the stack
						if((currentExComponent.getOperator()->getOpPres()) <= (stack.back().getOperator()->getOpPres()))
						{
							outputqueue.push_back(stack.back());
							stack.pop_back();
						}
					}
			}
			

			stack.push_back(currentExComponent);
		}

		else if(currentExComponent.Type == PARANTHESISO)
		{
			stack.push_back(currentExComponent);
		}

		else if(currentExComponent.Type == PARANTHESISC)
		{
			//Pop values off stack and into output until
			//we encounter a open parenthesis
			while(stack.back().Type != PARANTHESISO)
			{
				outputqueue.push_back(stack.back());
				stack.pop_back();

				if(stack.empty())
				{
					JcpuError("Error2: Mismatched Parenthesis?");
					break;
				}
			}
			//When we encounter a open Paranthesis:
			//Pop it off the stack
			stack.pop_back();

			//If after this the token at the top of the 
			//stack is a function pop it onto output
			if(!stack.empty() && stack.back().Type == FUNCTION)
			{
				outputqueue.push_back(stack.back());
				stack.pop_back();
			}
		}

		//When there are no more tokens to read
		if(i == input->length() - 1)
		{
			while(stack.empty() == false && stack.back().Type == OPERATOR)
			{
				outputqueue.push_back(stack.back());
				stack.pop_back();
			}
		}
	}
	arritystack = arrity;
	Expression tempex(outputqueue);
	return tempex;
}

Expression ExpressionEvaluator::evaluateToEx()
{
	Expression parsedEx = shuntingParse(curExpression);

	std::vector<ExpressionType> stack;
	
	for(int i = 0; i < parsedEx.length(); i++)
	{
		ExpressionType currentExComponent = parsedEx.at(i);

		if(currentExComponent.Type == NUMERIC)
		{
			stack.push_back(currentExComponent);
		}

		else
		{
			if(currentExComponent.Type == OPERATOR)
			{
				if(stack.size() < 2)
				{
					JcpuError("Error3: Insufficient arguments for operator " + currentExComponent.getOperator()->getOpName());
					break;
				}

				else if(stack.size() >= 2)
				{
					//Pop the last two arguments in the stack
					ExpressionType arg1 = stack[stack.size() - 2];
					ExpressionType arg2 = stack[stack.size() - 1];
					stack.pop_back();
					stack.pop_back();

					//Evaluate
					ExpressionType ans = currentExComponent.getOperator()->evaluate(arg1, arg2);

					//Push answer to stack
					stack.push_back(ans);
				}
			}

			if(currentExComponent.Type == FUNCTION)
			{
				int func_args = 0;

				if(currentExComponent.getFunction()->isVariadic() == true)
				{
					func_args = arritystack.front();
					arritystack.pop_front();
				}

				if(currentExComponent.getFunction()->isVariadic() == false)
				{
					func_args = currentExComponent.getFunction()->getFuncArgNum();
				}

				if(stack.size() < func_args)
				{
					JcpuError("Error4: Insufficient arguments for function " + currentExComponent.getFunction()->getFuncName());
					break;
				}

				else if(stack.size() >= func_args)
				{
					std::vector<ExpressionType> args;

					//loop through stack, pop the top n values into args
					for(int i = 0; i < func_args; i++)
					{
						args.push_back(stack[stack.size()-1]);
						stack.pop_back();
					}

					//Evaluate

					ExpressionType ans = currentExComponent.getFunction()->evaluate(args);

					stack.push_back(ans);
				}
			}
		}
	}

	if(stack.size() == 1)
	{
		Expression tempEx(stack);
		return tempEx;
	}

	else
	{
		JcpuError("Error5: Unknown cause");
	}
}

std::string ExpressionEvaluator::evaluateToStr()
{
	Expression ansEx = evaluateToEx();
	std::string writebuffer;

	for(int i = 0; i < ansEx.length(); i++)
	{
		ExpressionType currentExComponent = ansEx.at(i);
		if(currentExComponent.Type == NUMERIC)
		{
			writebuffer += std::to_string(currentExComponent.getNumeric());
			
		}

		if(currentExComponent.Type == OPERATOR)
		{
			writebuffer += currentExComponent.getOperator()->getOpName();
		}
	}

	return writebuffer;
}
