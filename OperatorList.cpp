#include "OperatorList.h"

int OperatorList::registerOp( OperatorBase* op)
{
	op->setOpIden(++funcidenbuffer);
	Operators.push_back(op);
	return Operators.back()->getOpIden();
}

 OperatorBase*  OperatorList::getOp(int iden)
{
	for(int i = 0; i <  Operators.size(); i++)
	{
		if( Operators[i]->getOpIden() == iden)
		{
			return  Operators[i];
		}
	}
	return nullptr;
}

OperatorBase*  OperatorList::getOp(std::string iden)
{
	for(int i = 0; i <  Operators.size(); i++)
	{
		if( Operators[i]->getOpName() == iden)
		{
			return  Operators[i];
		}
	}
	return nullptr;
}


bool OperatorList::exists(std::string iden)
{
	for(int i = 0; i <  Operators.size(); i++)
	{
		if( Operators[i]->getOpName() == iden)
		{
			return  true;
		}
	}
	return false;
}

OperatorList::OperatorList(void)
{
	OperatorList::funcidenbuffer = 0;
}


OperatorList::~OperatorList(void)
{
}
