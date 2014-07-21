#include <string>
#include <cmath>


#include "Expression.h"
#include "FunctionBase.h"
#include "SettingsInstance.h"


class Expression;
class OperatorBase;
class FunctionBase;
class SettingsInstance;


class modeF : public FunctionBase
{
public:
	ExpressionType evaluate(Expression input)
	{
		if(input.length() == 0)
		{
			if(screen != nullptr && settings != nullptr)
			{
				screen->addpath("Mode");
				screen->printCurPath();
				for(int i = 1; i < settings->settinglist.size(); i++)
				{
					screen->print(std::to_string(i) + settings->settinglist[i - 1].settingName);
				}

				bool found = false;

				while(found == false)
				{
					screen->print("Please select a setting number:");
					int input;
					std::cin>>input;
					if(input - 1 >= settings->settinglist.size())
					{
						screen->print("Invalid entry, please select again");
						found = false;
					}
					else
					{
						settings->set(settings->settinglist[input].settingName);
					}
				}

			}
		}

		ExpressionType temp("");
		return temp;
	}

	ExpressionType evaluate(std::vector<ExpressionType> input) 
	{
		if(input.size() == 0)
		{
			if(screen != nullptr && settings != nullptr)
			{
				screen->addpath("Mode");
				screen->printCurPath();
				for(int i = 0; i < settings->settinglist.size(); i++)
				{
					screen->print("\n" + std::to_string(i + 1) + ":" + settings->settinglist[i].settingName + "\n");
				}

				bool found = false;

				while(found == false)
				{
					screen->print("Please select a setting number: ");
					int input;
					std::cin>>input;
					if(input - 1 >= settings->settinglist.size())
					{
						screen->print("Invalid entry, please select again \n");
						found = false;
					}
					else
					{
						settings->set(settings->settinglist[input - 1].settingName);
						found = true;
					}
				}

			}
		}

		ExpressionType temp("");
		return temp;
	}

	int getFuncIden() 
	{
		return iden;
	}

	std::string getFuncName() 
	{
		return "mode";
	}

	int getFuncArgNum() 
	{
		return 0;
	}

	void setFuncIden(int idenin)
	{
		iden = idenin;
	}

	bool isVariadic()
	{
		return false;
	}

	bool requiresScreen()
	{
		return true;
	}

	bool requiresSettingsInstance()
	{
		return true;
	}
};

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

	bool requiresScreen()
	{
		return false;
	}

	bool requiresSettingsInstance()
	{
		return false;
	}
};

class sinF : public FunctionBase
{
public:

	ExpressionType evaluate(Expression input)
	{
		if(input.length() == 1)
		{
			//Get the value of the trig setting
			Setting* val = settings->find("Trignometric Unit");
			if(val != nullptr)
			{
				if(val->settingValue == "Degrees")
				{
					//Convert to degrees and solve
					double ans = sin(input.at(0).getNumeric()*3.14/180);
					ExpressionType tempex(ans);
					return tempex;
				}

				if(val->settingValue == "Radians")
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
				if(val->settingValue == "Degree")
				{
					//Convert to degrees and solve
					double ans = sin(input.at(0).getNumeric()*3.14/180);
					ExpressionType tempex(ans);
					return tempex;
				}

				if(val->settingValue == "Radian")
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

	bool requiresScreen()
	{
		return false;
	}

	bool requiresSettingsInstance()
	{
		return true;
	}
};