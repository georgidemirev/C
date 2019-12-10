#include "stdafx.h"
#include "Expr.h"
#include "VarExpression.h"
//using namespace std;

int main()
{
	ConstExpression<int>* expr = new ConstExpression<int>(15);

	expr->print();


	delete expr;
    return 0;
}

