#include "Expression.h"

using namespace std;

//Converts string to expression
Expression::Expression(string input, SystemState *state)
{
	vector<string> input_parts = inputSplit(input);

	for(unsigned int i = 0; i < input_parts.size(); i++)
	{
		//Check if the name is a regisered operator
		if(state->Operators->exists(input_parts[i]))
		{
			//Sets the tempType to the Operator object
			ExpressionType tempType(state->Operators->getOp(input_parts[i]));
			ExpressionVec.push_back(tempType);
		}

		//Check if the name is a registered function 
		else if(state->Functions->exists(input_parts[i]))
		{
			ExpressionType tempType(state->Functions->getFunc(input_parts[i]));
			ExpressionVec.push_back(tempType);
		}

		
		else if(input_parts[i] == "(" || input_parts[i] == ")" || input_parts[i] == ",")
		{
			//Gets the c_str of input_parts at i and passes the first char
			//(there should only be one) to ExpressionType
			ExpressionType tempType(input_parts[i].c_str()[0]);
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
	//Allow for unary operations
	bool unarypossible = true;
	bool unaryset = false;

	char currentchar = '\0';

	for(unsigned int i = 0;  i <= input.size(); i ++)
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

		else if(currentchar == '-' && unarypossible == true && isdigit(input[i+1]))
		{
			unaryset = true;
		}

		//Check if current char is a digit or decimal
		else if(isdigit(currentchar) || currentchar == '.')
		{
			if(readingbuffer == true)
			{
				writebuffer += currentchar;
			}

			else if(readingbuffer == false)
			{
				if(unaryset == true)
				{
					writebuffer += '-';
					writebuffer +=currentchar;
					readingbuffer = true;
					unaryset = false;
				}
				else
				{
					writebuffer +=currentchar;
					readingbuffer = true;
				}
			}

			unarypossible = false;
		}

		//Check is current char is a '[' char, the opening charecter of a matrix
		else if(currentchar == '[')
		{
			//Reads through input until it finds closing operator
			while(currentchar != ']'  && i != input.size())
			{
				currentchar = input[i];
				writebuffer += currentchar;
				i++;
			}
			bufferlist.push_back(writebuffer);
			writebuffer.clear();
			readingbuffer = false;
		}

		//Check if digit is a character, in the case that it is a char it
		//will be pushed until a paranthesis is encountered
		else if(isalpha(currentchar))
		{
			//We advance i and check for a '(' each loop, while pushing the
			//next char until parenthesis is found
			while(input[i] != '(')
			{
				writebuffer += input[i];
				i++;

				if(i >= input.size())
				{
					JcpuError("Error6: Expected function?");
					break;
				}
			}
			//Push the function
			bufferlist.push_back(writebuffer);
			writebuffer.clear();
			//Generate a temporary string with a paranthesis and pushes that
			//since the parenthesis is lost in the above loop
			if(input[i] == '(')
			{
				std::string tempStr("(");
				bufferlist.push_back(tempStr);
			}
			unarypossible = true;
		}

		//Check if current char is a left parenthesis
		else if(currentchar == '(')
		{
			bufferlist.push_back("(");
			writebuffer.clear();
			unarypossible = true;
		}

		//Assumes the char is an operator, if the algorthim cant 
		//correctly identify the charecter as a digit, decimal
		//point, alphabetical value, or parenthesis it will assume 
		//it is an operator.
		else {
			unarypossible = true;
			if(currentchar == ')')
			{
				unarypossible = false;
			}

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
					readingbuffer = false;
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

