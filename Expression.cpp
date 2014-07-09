#include "Expression.h"

using namespace std;

//Converts string to expression
Expression::Expression(string input, SystemState *state)
{
	vector<string> input_parts = inputSplit(input);

	for(int i = 0; i < input_parts.size(); i++)
	{
		//Check if the name is a regisered operator
		if(state->Operators->exists(input_parts[i]))
		{
			//Sets the tempType to the Operator object
			ExpressionType tempType(state->Operators->getOp(input_parts[i]));
			ExpressionVec.push_back(tempType);
		}
		//Assumes it to be a double 
		//Note: A safer solution should be implemented
		else
		{
			double number = atof(input_parts[i].c_str());
			ExpressionType tempType(number);
			ExpressionVec.push_back(tempType);
		}
	}
}


vector<string> Expression::inputSplit(string input)
{
	string writebuffer;
	vector<string> bufferlist;
	bool readingbuffer = false;

	char currentchar = '\0';

	for(int i = 0;  i <= input.size(); i ++)
	{

		currentchar = input[i];

		//Check if we're done iterating
		if (i == input.size())
		{
			//Check if write buffer is empty
			if(writebuffer != "")
			{
				//Empty buffer
				bufferlist.push_back(writebuffer);
				writebuffer.clear();
				readingbuffer = false;
				break;
			}

			else{
				break;
			}
		}

		//Check if current char is a digit or decimal
		else if(isdigit(currentchar) || currentchar == '.')
		{
			if(readingbuffer == true)
			{
				writebuffer += currentchar;
			}

			if(readingbuffer == false)
			{
				writebuffer +=currentchar;
				readingbuffer = true;
			}
		}
		//Assumes the char is an operator, if the algorthim cant 
		//correctly identify the charecter as a digit, decimal
		//point, alphabetical value, or parenthesis it will assume 
		//it is an operator.
		else {
			if(!writebuffer.empty())
			{
				if(readingbuffer == true)
				{
					//Pushes the current write buffer to the bufferlist
					bufferlist.push_back(writebuffer); 
					writebuffer.clear();
					//Creates temporary string contaning the operator
					string tempcharstr(1, currentchar);
					//Pushes it onto bufferlist
					bufferlist.push_back(tempcharstr);
				}
			}

			else if(writebuffer.empty() || readingbuffer == false)
			{
				//Creates temporary string contaning the operator
				string tempcharstr(1, currentchar);
				//Pushes it onto bufferlist
				bufferlist.push_back(tempcharstr);
			}
		}
	}

	return bufferlist;
}

Expression::Expression(std::vector<ExpressionType> ExpressionVecin)
{
	ExpressionVec = ExpressionVecin;
}

void Expression::addExType(ExpressionType newex)
{
	ExpressionVec.push_back(newex);
}

ExpressionType Expression::at(int loc)
{
	return ExpressionVec[loc];
}

double Expression::doubat(int loc)
{
	return ExpressionVec[loc].getNumeric();
}

std::string Expression::stringat(int loc)
{
		return ExpressionVec[loc].getString();
}

int Expression::length()
{
	return ExpressionVec.size();
}