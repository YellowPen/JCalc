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

Expression ExpressionEvaluator::shuntingParse(Expression *input)
{
	std::vector<ExpressionType> stack;
	std::vector<ExpressionType> outputqueue;

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
			//Do Stuff
		}

		else if(currentExComponent.Type == COMMA)
		{
			//Do stuff
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
					//Error
				}

				else if(stack.size() >= 2)
				{
					//Pop the last two arguments in the stack
					ExpressionType arg1 = stack[stack.size() - 1];
					ExpressionType arg2 = stack[stack.size() - 2];
					stack.pop_back();
					stack.pop_back();

					//Evaluate
					ExpressionType ans = currentExComponent.getOperator()->evaluate(arg1, arg2);

					//Push answer to stack
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
		//Error
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