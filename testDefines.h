#include "Expression.h"
#include "OperatorBase.h"

class Expression;
class OperatorBase;

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
		double ans = (a.getNumeric()) - (a.getNumeric());
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

