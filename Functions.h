#include <cmath>


#include "Expression.h"
#include "FunctionBase.h"
#include "SettingsInstance.h"


class Expression;
class OperatorBase;
class FunctionBase;
class SettingsInstance;

class sqrtF : public FunctionBase
{
	
	ExpressionType evaluate(Expression input)
	{
		if(input.length() == 1)
		{
			double ans = sqrt(input.at(0).getNumeric());
			ExpressionType tempex(ans);
			return tempex;
		}
	}

	ExpressionType evaluate(std::vector<ExpressionType> input) 
	{
		//Make sure there are the correct args arguments
		if(input.size() == 1)
		{
			double ans = sqrt(input[0].getNumeric());
			ExpressionType tempex(ans);
			return tempex;
		}
	}

	int getFuncIden() 
	{
		return iden;
	}

	std::string getFuncName() 
	{
		return "sqrt";
	}

	int getFuncArgNum() 
	{
		return 1;
	}

	void setFuncIden(int idenin)
	{
		iden = idenin;
	}

	bool isVariadic()
	{
		return false;
	}
};

class sinF : public FunctionBase
{
public:
	sinF(SettingsInstance* settingsin)
	{
		settings = settingsin;
	}

	sinF(void)
	{
		SettingsInstance tempsettings;
	}

	ExpressionType evaluate(Expression input)
	{
		if(input.length() == 1)
		{
			//Get the value of the trig setting
			Setting* val = settings->find("Trignometric Unit");
			if(val != nullptr)
			{
				if(val->value == "Degrees")
				{
					//Convert to degrees and solve
					double ans = sin(input.at(0).getNumeric()*3.14/180);
					ExpressionType tempex(ans);
					return tempex;
				}

				if(val->value == "Radians")
				{
					//solve
					double ans = sin(input.at(0).getNumeric());
					ExpressionType tempex(ans);
					return tempex;
				}
			}
		}
	}

	ExpressionType evaluate(std::vector<ExpressionType> input) 
	{
		if(input.size() == 1)
		{
			//Get the value of the trig setting
			Setting* val = settings->find("Trignometric Unit");
			if(val != nullptr)
			{
				if(val->value == "Degree")
				{
					//Convert to degrees and solve
					double ans = sin(input.at(0).getNumeric()*3.14/180);
					ExpressionType tempex(ans);
					return tempex;
				}

				if(val->value == "Radian")
				{
					//solve
					double ans = sin(input.at(0).getNumeric());
					ExpressionType tempex(ans);
					return tempex;
				}
			}
		}
	}

	int getFuncIden() 
	{
		return iden;
	}

	std::string getFuncName() 
	{
		return "sin";
	}

	int getFuncArgNum() 
	{
		return 1;
	}

	void setFuncIden(int idenin)
	{
		iden = idenin;
	}

	bool isVariadic()
	{
		return false;
	}
private:
	SettingsInstance* settings;
};