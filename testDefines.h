#include <cmath>


#include "Expression.h"
#include "OperatorBase.h"
#include "FunctionBase.h"

class Expression;
class OperatorBase;
class FunctionBase;

class plusO : public OperatorBase
{
	ExpressionType evaluate(Expression a)
	{
		double ans = (a.at(0).getNumeric()) + (a.at(1).getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	ExpressionType evaluate(ExpressionType a, ExpressionType b)
	{
		double ans = (a.getNumeric()) + (b.getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	int getOpIden()
	{
		return iden;
	}

	int getOpPres()
	{
		return 2;
	}

	std::string getOpName()
	{
		return "+";
	}

	bool  isLeftAssociative()
	{
		return true;
	}

	void setOpIden(int idenin)
	{
		iden = idenin;
	}
};

class minusO : public OperatorBase
{
	ExpressionType evaluate(Expression a)
	{
		double ans = (a.at(0).getNumeric()) - (a.at(1).getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	ExpressionType evaluate(ExpressionType a, ExpressionType b)
	{
		double ans = (a.getNumeric()) - (b.getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	int getOpIden()
	{
		return iden;
	}

	int getOpPres()
	{
		return 2;
	}

	std::string getOpName()
	{
		return "-";
	}

	bool  isLeftAssociative()
	{
		return true;
	}

	void setOpIden(int idenin)
	{
		iden = idenin;
	}
};

class mulO : public OperatorBase
{
	ExpressionType evaluate(Expression a)
	{
		double ans = (a.at(0).getNumeric()) * (a.at(1).getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	ExpressionType evaluate(ExpressionType a, ExpressionType b)
	{
		double ans = (a.getNumeric()) * (b.getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	int getOpIden()
	{
		return iden;
	}

	int getOpPres()
	{
		return 3;
	}

	std::string getOpName()
	{
		return "*";
	}

	bool  isLeftAssociative()
	{
		return true;
	}

	void setOpIden(int idenin)
	{
		iden = idenin;
	}
};

class divO : public OperatorBase
{
	ExpressionType evaluate(Expression a)
	{
		double ans = (a.at(0).getNumeric()) / (a.at(1).getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	ExpressionType evaluate(ExpressionType a, ExpressionType b)
	{
		double ans = (a.getNumeric()) / (b.getNumeric());
		ExpressionType tempex(ans);
		return tempex;
	}

	int getOpIden()
	{
		return iden;
	}

	int getOpPres()
	{
		return 3;
	}

	std::string getOpName()
	{
		return "/";
	}

	bool  isLeftAssociative()
	{
		return true;
	}

	void setOpIden(int idenin)
	{
		iden = idenin;
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
};

